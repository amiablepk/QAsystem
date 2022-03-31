/*******************************************************************************

main file for search engine from text files


/***** #includes **************************************************************/

#include "stdafx.h"

#include "getopt.h"

#include <math.h>
#include <limits.h>
#include <float.h>

#include <sys/types.h>
#include <ctype.h>
#include "seft.h"
#include "util.h"
#include "words.h"
#include "local_strings.h"
#include "heap.h"
#include "stem.h"


/***** #defines and Macros ****************************************************/

#define K_APPROX 63              /* used to calculate approx n (unique words) */
#define B_APPROX 0.47

/***** Function Prototypes ****************************************************/



/*******************************************************************************
*
* Function: main
*
*******************************************************************************/


int main_seft(int argch, char* argvh[],char message[10][10000])
{
    query_data qd;
    int i;
    FILE* fptr;
	optind=0;
	//sprintf(final_answer," ");
//	AfxMessageBox("check",MB_OK);
    process_args(argch,argvh,&qd);

    init_qd(&qd);
    
    if (optind > (argch-1))
        usage(argvh[0]);
        
    if (qd.file_name != NULL)
        {
        process_query_file(&qd);                    // query from file
        }
    else
        {
		//AfxMessageBox("ch",MB_OK);
        qd.query_string = safe_strdup(argvh[optind]);
        process_query_line(&qd,qd.query_string);    // query from command line
        optind++;
        }

    for (i=optind; i < argch; i++)
        {
        fptr = safe_fopen(argvh[i],"r");

	//	AfxMessageBox("open",MB_OK);

        process_text_files(&qd,fptr,&(argvh[i]));
		
	//	AfxMessageBox("processed",MB_OK);

        fclose(fptr);
        }

    qd.N = qd.curr_pos - 1;

    calc_weights(&qd);

    calc_accumulators(decay_circle,&qd);


    selection(&qd,message);
	

    return (0);
}


/*******************************************************************************
*
* Function: init_qd
*
* Purpose:  initialise the query data structure
*
*******************************************************************************/

void
init_qd(query_data* qd)
{
    int i;
    int k = ASCII7 * ASCII7;

    qd->seek_buffer = 
        (long*)safe_malloc(qd->window_size*sizeof(long));

    for (i=0; i < qd->window_size; i++)
        {
        qd->seek_buffer[i] = 0;
        }

    qd->word_array = (WORD_SEFT*)safe_malloc(INIT_WORD_SIZE*sizeof(WORD_SEFT));
    qd->query_table = (TERM*)safe_malloc(INIT_TERM_SIZE*sizeof(TERM));
    qd->doc_idx =    (long*)safe_malloc(MAX_DOCS*sizeof(long));
    qd->max_words = INIT_WORD_SIZE;
    qd->max_terms = INIT_TERM_SIZE;
    qd->no_words = 0;
    qd->line_no = 0;    
    qd->curr_pos = 1;
    qd->no_docs = 0;
    qd->no_terms = 0;
    qd->tst_root = NULL;


    qd->min_length = MAX_QUERY_LEN;

    // sentinal for heap selection
    qd->word_array[0].pos = 0;
    qd->word_array[0].termptr = NULL;
    qd->word_array[0].level = FLT_MAX;


    qd->lookup = (int*)safe_malloc(k*sizeof(int));
    for (i=0; i < k; i++)
        qd->lookup[i] = 256;

}

/*******************************************************************************
*
* Function: process_args
*
* Purpose:  process the command line arguments
*
*******************************************************************************/

void process_args(int argc, char* argv[], query_data *qd)
{
    int ch;
    
    // set argument defaults
    
    qd->file_name    = NULL;
    qd->query_string = NULL;
    qd->window_size = DEFAULT_WINDOW_SIZE;
    qd->doc_separator = NULL;
    qd->max_windows = DEFAULT_MAX_WINDOWS;
    qd->no_output = FALSE;
    qd->no_hilite = FALSE;
    qd->stem_method = 3;
    qd->do_formfeed = FALSE;

    // process arguments
    
    while ((ch = getopt (argc, argv, "phs:xnm:f:w:d:")) != -1)
        switch (ch) 
        {
        case 'f' :                        /* input file */
            qd->file_name = strdup(optarg);
            break;
        case 'd' :
            qd->doc_separator = strdup(optarg);
            break;
        case 'w' :
            qd->window_size = atoi(optarg);
            break;
        case 'm' :
            qd->max_windows = atoi(optarg);
            break;
        case 'p' :
            qd->do_formfeed = TRUE;
            break;
        case 'x' :
            qd->no_hilite = TRUE;
            break;
        case 's' :
            qd->stem_method = atoi(optarg);
            if (qd->stem_method < 0 || qd->stem_method > 2)
                usage(argv[0]); 
            if (qd->stem_method == 2)
                qd->stem_method = 3;
            break;
        case 'n' :
            qd->no_output = TRUE;
            break;
        case 'h' :
        case '?' :
        default:
            usage(argv[0]);
      }

    if (qd->doc_separator == NULL)
            qd->doc_separator = strdup("");

}

/*******************************************************************************
*
* Function: process_query_line
*
* Purpose:  parse a query line of text and insert words into hash table
*
*******************************************************************************/

void 
process_query_line(query_data* qd, char* line)
{
    u_char *end, *s_in;
    u_char Word[MAXSTEMLEN];
    int index;
    int calc;

    if (line == NULL)
        return;

    s_in = (u_char*)line;
    end = s_in + strlen((char*)s_in) - 1;

    if (!INAWORD(*s_in))
        PARSE_NON_WORD_DISCARD(s_in, end);

    while ( s_in <= end) 
        {
        /* Get a word and stem it */
        PARSE_WORD(Word, s_in, end);

        stemmer(qd->stem_method,Word);

        if (Word[0] < qd->min_length)
            {
            qd->min_length = Word[0];
            }



        if (qd->stem_method == 0)
            {
            calc = ((Word[1] & 127u) << 7) | (Word[2] & 127u);
            if (qd->lookup[calc] > Word[0])
                {
                qd->lookup[calc] = Word[0];
                }
            }
        else
            {
            calc = ((toupper(Word[1]) & 127u) << 7) | (toupper(Word[2]) & 127u);
            if (qd->lookup[calc] > Word[0])
                {
                qd->lookup[calc] = Word[0];
                calc = ((tolower(Word[1]) & 127u) << 7) | (toupper(Word[2]) & 127u);
                qd->lookup[calc] = Word[0];
                calc = ((tolower(Word[1]) & 127u) << 7) | (tolower(Word[2]) & 127u);
                qd->lookup[calc] = Word[0];
                calc = ((toupper(Word[1]) & 127u) << 7) | (tolower(Word[2]) & 127u);
                qd->lookup[calc] = Word[0];
                }
            }

        Word[Word[0]+1] = '\0';

        index = tst_search(qd->tst_root,(char *) Word);

        if (index == NOT_FOUND)
            {
            if (qd->no_terms == qd->max_terms)
                {
                qd->query_table = (TERM*)safe_realloc(qd->query_table,
                        (qd->max_terms + INCR_TERM_SIZE)*sizeof(TERM));
                qd->max_terms += INCR_TERM_SIZE;
                }

            qd->query_table[qd->no_terms].Word = copy_string(Word);
            qd->query_table[qd->no_terms].fqt = 1;
            qd->query_table[qd->no_terms].ft = 0;
            qd->query_table[qd->no_terms].spread = 0;
            qd->query_table[qd->no_terms].init_height = 0;
            qd->query_table[qd->no_terms].term_num = qd->no_terms+1;

            qd->tst_root = tst_insert(qd->tst_root, (char *)Word, qd->no_terms);
                                        
            qd->no_terms++;
            }
         else
            {
            qd->query_table[index].fqt++;
            }

        PARSE_NON_WORD_DISCARD(s_in, end);
        }
}

/*******************************************************************************
*
* Function: process_query_file
*
* Purpose:  parse a file containing query terms
*
*******************************************************************************/

void 
process_query_file(query_data* qd)
{
    char line[MAX_QUERY_LEN];

    if (qd->file_name == NULL)

        return;

    qd->query_file = safe_fopen(qd->file_name,"r");

    while (fgets(line,MAX_QUERY_LEN,qd->query_file) != NULL)
    {
        process_query_line(qd, line);
    }
    
    fclose(qd->query_file);
}

/*******************************************************************************
*
* Function: calc_weights
*
* Purpose:  calculate height and spread factors (using Heap' Law)
*
*******************************************************************************/

void 
calc_weights(query_data* qd)
{
    int i;

    for (i=0; i < qd->no_terms; i++)
        {
        if (qd->query_table[i].ft != 0)
            {
        qd->query_table[i].init_height = (float)log(((float)qd->N/(float)
                qd->query_table[i].ft)) * qd->query_table[i].fqt;
        qd->query_table[i].spread = (int)((K_APPROX*pow(qd->N,B_APPROX)) /
                                    (float)qd->query_table[i].ft); 
            }
        }

    for (i=1; i < qd->no_words+1; i++)
            qd->word_array[i].level = qd->word_array[i].termptr->init_height;
}


/*******************************************************************************
*
* Function: calc_accumulators
*
* Purpose:  calculate contribution curves and update location accumulators
*
*******************************************************************************/

void
calc_accumulators(float (*shape)(long,int),query_data* qd)
{

    int i,l;
    
    int doci = 0;
    long dist;
    int spread;
    float contrib;
    long lower;
    
    for (i=1; i <= qd->no_words; i++)
        {
        l = i+1;
        
        spread = qd->word_array[i].termptr->spread;
        
        while (qd->word_array[i].pos > qd->doc_idx[doci])
            {
            doci++;
            }
        while ((l <= qd->no_words) && (qd->word_array[l].pos <= qd->doc_idx[doci]))
            {
            dist = qd->word_array[l].pos - qd->word_array[i].pos;

            if (dist <= spread)
                {
                if (qd->word_array[i].termptr->term_num !=
                    qd->word_array[l].termptr->term_num)
                    {
                    contrib = qd->word_array[i].termptr->init_height *
                                            shape(dist,spread);
                    qd->word_array[l].level += contrib; 
                    }
                }
            else
                {
                break;
                }
            l++;
            }

        l = i-1;

        if (doci == 0)
            lower = 0;
        else 
            lower = qd->doc_idx[doci-1];


        while ((l > 0) && (qd->word_array[l].pos > lower))
            {
            dist =  qd->word_array[i].pos - qd->word_array[l].pos;

            if (dist <= spread)
                {
                if (qd->word_array[i].termptr->term_num !=
                                qd->word_array[l].termptr->term_num)
                    {
                    contrib = qd->word_array[i].termptr->init_height *
                                            shape(dist,spread);

                    qd->word_array[l].level += contrib;   
                    }
                }
            else
                {
                break;
                }
            l--;
            }
        }
}

/*******************************************************************************
*
* Function: decay_circle
*
* Purpose:  a particular contribution curve shape 
*
*******************************************************************************/

float
decay_circle(long dist, int D)
{
    double y;

    double point = (double)dist/(double)D;

    y = 1 - (sqrt((2*point) - (point*point)));

    return (float)(y);
}

/*******************************************************************************
*
* Function: selection
*
* Purpose:  select top (max_windows) term locations (windows) in ranked order
*
*******************************************************************************/

void
selection(query_data* qd,char message[5][10000])
{
    WORD_SEFT** ptr_array;
    int i,j;
    int heap_size = qd->no_words;
    WORD_SEFT* word;
    float max_score = 0;
    int score;
    WORD_SEFT** merge_search;
    bool output_flag;
    int line_min, line_max;
    
    ptr_array =  (WORD_SEFT**)safe_malloc((qd->no_words+1)*sizeof(WORD_SEFT*));
    merge_search = (WORD_SEFT**)safe_malloc(qd->max_windows*sizeof(WORD_SEFT*));

    for(i=0; i <= qd->no_words; i++)
        ptr_array[i] = &(qd->word_array[i]);


    for (i=heap_size/2; i >=1; i--)
        ptr_array = heap_down(ptr_array,i,heap_size);

    i = 1;
    while (i <= qd->max_windows)
        {
        if (heap_size == 0)
            {
            break;
            }
        word = heap_remove(ptr_array,&heap_size);
        merge_search[i-1] = word;

        if (i == 1)
            {
            max_score = word->level;
            }

        // check for window merging 
        output_flag = TRUE;

        for (j=0; j < (i-1); j++)
            {
            // check filenames
            if (strcmp(*(word->name),*(merge_search[j]->name)) == 0)
                {
                // check window boundaries
                line_min = merge_search[j]->line_no - (qd->window_size/2);
                line_max = merge_search[j]->line_no + (qd->window_size/2);
                if ((qd->window_size % 2) == 0)
                    line_max--;
                if ((word->line_no >= line_min) && (word->line_no <= line_max))
                    {
                    output_flag = FALSE;
                    break;
                    }
                }
            }

        if (output_flag == TRUE)
            {
                score = (int)((word->level*100)/max_score);
				sprintf(message[j]," ");
                output_window(qd, word, i, score,message[j]);
                if ((qd->no_output == FALSE) && (qd->do_formfeed == TRUE))
                    sprintf(message[j],"%s \f\n",message[j]);
                i++;
                }
			
            }
	
	return ;
    }

/*******************************************************************************
*
* Function: process_text_files
*
* Purpose:  extract line of input text, buffer and note seek position
*
*******************************************************************************/

void
process_text_files(query_data* qd, FILE* fptr, char** name)
{
    int half = qd->window_size/2;
    char line[MAX_QUERY_LEN];

    if (qd->window_size%2 == 0)
        half--;

    qd->line_no = 0;

    while (fgets(line,MAX_QUERY_LEN,fptr) != NULL)
        {
        qd->seek_buffer[qd->line_no%qd->window_size] = ftell(fptr);
        process_text(qd,
                     qd->seek_buffer[(qd->line_no+half)%qd->window_size],
                     name,line);
        qd->line_no++;
        }

    qd->no_docs++;
    qd->doc_idx[qd->no_docs-1] = qd->curr_pos-1;
}

/*******************************************************************************
*
* Function: process_text
*
* Purpose:  parse lines of text, determine whether word is in hash table
*
*******************************************************************************/

void 
process_text(query_data* qd, long seek_pos, char** name, char* line)
{
    u_char *end, *s_in;
    u_char Word[MAXSTEMLEN];
    int flag = 0;
    int index;
    int calc; 


    s_in = (u_char*)line;
    end = s_in + strlen((char*)s_in) - 1;

    if (!INAWORD(*s_in))
        {
        PARSE_NON_WORD_FLAG(flag,s_in, end);

        if (flag == 1)
            {
            qd->no_docs++;
            qd->doc_idx[qd->no_docs-1] = qd->curr_pos-1;
            flag = 0;
            }
        }

    while ( s_in <= end) 
        {
        /* Get a word */
        PARSE_WORD(Word, s_in, end);


        calc = ((Word[1] & 127u) << 7) | (Word[2] & 127u);
        if (Word[0] >= qd->lookup[calc]) 
                {
                stemmer(qd->stem_method,Word);
                Word[Word[0]+1] = '\0';
                index = tst_search(qd->tst_root,(char *)Word);

                if (index != -1)
                    {
                    if (qd->no_words == (qd->max_words-1))
                        {
                        qd->word_array = (WORD_SEFT*)safe_realloc(qd->word_array,
                        (qd->max_words + INCR_WORD_SIZE)*sizeof(WORD_SEFT));
                        qd->max_words += INCR_WORD_SIZE;
                        }

                    qd->query_table[index].ft++;
                    qd->no_words++;

                    qd->word_array[qd->no_words].no = qd->no_words;
                    qd->word_array[qd->no_words].termptr = &( qd->query_table[index]);
                    qd->word_array[qd->no_words].pos = qd->curr_pos;
                    qd->word_array[qd->no_words].name = name;
                    qd->word_array[qd->no_words].line_no = qd->line_no+1;
                    qd->word_array[qd->no_words].seek_pos = seek_pos;
                    }
                }
       qd->curr_pos++;

       // parse non-word, check for doc separator
            
       PARSE_NON_WORD_FLAG(flag,s_in, end);
       if (flag == 1)
           {
           qd->no_docs++;
           qd->doc_idx[qd->no_docs-1] = qd->curr_pos-1;
           flag = 0;
           }
       }
}

/*******************************************************************************
*
* Function: usage
*
* Purpose:  display usage message and exit
*
*******************************************************************************/

void  usage(char* progname)
{
    /*    fprintf(stderr, "usage: %s "
                        "[-nxh] "
                        "[-s 0|1|2] "
                        "[-f query_file] "
                        "[-w window_size] "
                        "[-m max_windows] "
                        "\"query terms\" text_files\n",
                        progname); */
        exit(1);
}

/******************************************************************************/


void
output_window(query_data* qd, WORD_SEFT* word, int rank, int score,char* message)
{
// AfxMessageBox("enter",MB_OK);
    if (qd->no_output == FALSE)
        {

        output_window_header(word,rank,score,message);
        output_sparse_window(qd, word,message);
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
output_window_header(WORD_SEFT* word, int rank, int score,char* final_answer)
{
    char line[MAX_LINE_LENGTH*2];
    int length;
    int i;
    int line_diff;

    sprintf(line," \r\n == %2d (%3d%%) == %s:%d ========= \r\n ",
                rank, score, *(word->name), word->line_no);
    
    sprintf(final_answer,"%s %s",final_answer,line);
	//AfxMessageBox(line,MB_OK);

    length = strlen(line);
    line_diff = MAX_LINE_LENGTH - length -1;

   /* for (i=0; i < line_diff; i++)
        {
        sprintf(final_answer,"%s =",final_answer);
        } 
      sprintf(final_answer,"%s \n",final_answer);
	  */
}

/*******************************************************************************
*
* Function: output_null_window
*
* Purpose:  perform seek only (useful for timing)
*
*******************************************************************************/

void
output_null_window(query_data* qd, WORD_SEFT* word)
{
    FILE* fptr;
    int i;
    char buffer[MAX_QUERY_LEN];

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
output_sparse_window(query_data* qd, WORD_SEFT* word,char* final_answer)
{
   // AfxMessageBox("passage",MB_OK);
	u_char Word[MAXSTEMLEN];
    u_char copy_word[MAXSTEMLEN];
    u_char *end, *s_in;
    FILE* fptr;
    int i;
    char buffer[MAX_QUERY_LEN];
	char str[256];

    fptr = safe_fopen(*(word->name),"rb");
    fseek(fptr,word->seek_pos,SEEK_SET);

    for (i=0; i < qd->window_size; i++)
        {
        fgets(buffer,MAX_QUERY_LEN,fptr);

        if (qd->no_hilite == TRUE)
            {
             sprintf(final_answer,"%s %s",final_answer,buffer);
			//AfxMessageBox(buffer,MB_OK);
            }		
        else
            {
            s_in = (u_char*)buffer;
            end = s_in + strlen((char*)s_in) - 1;

            if (!INAWORD(*s_in))
                {
                PARSE_NON_WORD(Word,s_in, end);
                //print_str255(Word,stdout);
					str255_to_string(Word,str);
				    //strcpy(Word,str);
					sprintf(final_answer,"%s %s ",final_answer,str);
				
                }
            while ( s_in <= end)
                {
                /* Get a word */
                PARSE_WORD(Word, s_in, end);

                //tolower_word = copy_string_tolower(Word);
                string_copy(copy_word,Word); 
                
                stemmer(qd->stem_method,copy_word);

                copy_word[copy_word[0]+1] = '\0';

                if (tst_search(qd->tst_root,(char *)copy_word) != NOT_FOUND)
                    {
                     sprintf(final_answer,"%s \033",final_answer);
                    
					//print_str255(Word,stdout);
					 
					str255_to_string(Word,str);
					// strcpy((char*)Word,str);
					sprintf(final_answer,"%s %s ",final_answer,str);
                    sprintf(final_answer,"%s \033",final_answer); 
					
                    }
                 else
                    {
					 //print_str255(Word,stdout);
					 
				
					str255_to_string(Word,str);
					 //strcpy((char*)Word,str);
					sprintf(final_answer,"%s %s ",final_answer,str);
                    }

                 PARSE_NON_WORD(Word,s_in, end);
				 //print_str255(Word,stdout);
				 str255_to_string(Word,str);
				 //strcpy((char*)Word,str);
				 sprintf(final_answer,"%s %s ",final_answer,str);

                 }
            }
        }
     sprintf(final_answer,"%s \r\n",final_answer);

}


/* tst.cpp*/

Tptr 
tst_insert(Tptr p, char *s, int index)
{   
    if (p == NULL) 
        {
        p = (Tptr) safe_malloc(sizeof(Tnode));
        p->splitchar = *s;
        p->lokid = p->eqkid = p->hikid = NULL;
        p->term_index = NOT_FOUND;
        }
    if (*s < p->splitchar)
        {
        p->lokid = tst_insert(p->lokid, s, index);
        }
    else if (*s == p->splitchar) 
        {
        if (*s == '\0')
            {
            p->term_index = index;
            }
        else
            {
            p->eqkid = tst_insert(p->eqkid, ++s, index);
            }
        } 
    else
        {
        p->hikid = tst_insert(p->hikid, s, index);
        }

    return (p);
}

void 
cleanup(Tptr p)
{   
    if (p) 
        {
		cleanup(p->lokid);
		if (p->splitchar) 
            {
            cleanup(p->eqkid);
            }
		cleanup(p->hikid);
		free(p);
        }
}

int 
tst_search(Tptr root,char *s)
{   
    Tptr p;
    p = root;
    while (p) 
        {
        if (*s < p->splitchar)
            {
            p = p->lokid;
            }
        else if (*s == p->splitchar)  
            {
            if (*s++ == 0)
                {
                return (p->term_index);
                }
            p = p->eqkid;
            } 
        else
            {
            p = p->hikid;
            }
        }

    return (NOT_FOUND);
}
