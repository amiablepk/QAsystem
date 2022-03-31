/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         output.c
*
* Author:       Owen de Kretser (oldk@cs.mu.oz.au)
*
* Organisation: Dept. of CS&SE, University of Melbourne
*
* Date:         April 1999
*
* Purpose:      window printing functions
*
*******************************************************************************/

/***** #includes **************************************************************/

#include "stdafx.h"
#include <string.h>
#include "output.h"
#include "util.h"
#include "local_strings.h"
#include "main.h"
#include "words.h"
#include "stem.h"
#include "tst.h"

/***** Function Prototypes ****************************************************/

void output_window_header(WORD*, int rank, int score);
void output_sparse_window(query_data*, WORD*);
void output_null_window(query_data*, WORD*);


/*******************************************************************************
*
* Function: output_window
*
* Purpose:  seek into text file and extract/output an appropriate window
*
*******************************************************************************/

void
output_window(query_data* qd, WORD* word, int rank, int score)
{

    if (qd->no_output == FALSE)
        {
        output_window_header(word,rank,score);
        output_sparse_window(qd, word);
        }
    else
        {
        output_null_window(qd,word);
        }
}

/*******************************************************************************
*
* Function: output_window_header
*
* Purpose:  output window header information
*
*******************************************************************************/

void
output_window_header(WORD* word, int rank, int score)
{
    char line[MAX_LINE_LENGTH*2];
    int length;
    int i;
    int line_diff;

    sprintf(line,"== %2d (%3d%%) == %s:%d ",
                rank, score, *(word->name), word->line_no);
    
    fprintf(stdout,"%s",line);

    length = strlen(line);
    line_diff = MAX_LINE_LENGTH - length -1;

    for (i=0; i < line_diff; i++)
        {
        fprintf(stdout,"=");
        }
    fprintf(stdout,"\n");
}

/*******************************************************************************
*
* Function: output_null_window
*
* Purpose:  perform seek only (useful for timing)
*
*******************************************************************************/

void
output_null_window(query_data* qd, WORD* word)
{
    FILE* fptr;
    int i;
    u_char buffer[MAX_QUERY_LEN];

    fptr = safe_fopen(*(word->name),"rb");
    fseek(fptr,word->seek_pos,SEEK_SET);
    for (i=0; i < qd->window_size; i++)
        {
        fgets(buffer,MAX_QUERY_LEN,fptr);
        }
    fclose(fptr);
}

/*******************************************************************************
*
* Function: output_sparse_window
*
* Purpose:  output window in sparse (original) format 
*
*******************************************************************************/

void
output_sparse_window(query_data* qd, WORD* word)
{
    u_char Word[MAXSTEMLEN];
    u_char copy_word[MAXSTEMLEN];
    u_char *end, *s_in;
    FILE* fptr;
    int i;
    u_char buffer[MAX_QUERY_LEN];

    fptr = safe_fopen(*(word->name),"rb");
    fseek(fptr,word->seek_pos,SEEK_SET);

    for (i=0; i < qd->window_size; i++)
        {
        fgets(buffer,MAX_QUERY_LEN,fptr);

        if (qd->no_hilite == TRUE)
            {
            fprintf(stdout,"%s",buffer);
            }
        else
            {
            s_in = (u_char*)buffer;
            end = s_in + strlen((char*)s_in) - 1;

            if (!INAWORD(*s_in))
                {
                PARSE_NON_WORD(Word,s_in, end);
                print_str255(Word,stdout);
                }
            while ( s_in <= end)
                {
                /* Get a word */
                PARSE_WORD(Word, s_in, end);

                //tolower_word = copy_string_tolower(Word);
                string_copy(copy_word,Word); 
                
                stemmer(qd->stem_method,copy_word);

                copy_word[copy_word[0]+1] = '\0';

                if (tst_search(qd->tst_root,copy_word) != NOT_FOUND)
                    {
                    fprintf(stdout,"\033[7m");
                    print_str255(Word,stdout);
                    fprintf(stdout,"\033[m");
                    }
                 else
                    {
                    print_str255(Word,stdout);
                    }

                 PARSE_NON_WORD(Word,s_in, end);
                 print_str255(Word,stdout);
                 }
            }
        }
    fprintf(stdout,"\n");
}


