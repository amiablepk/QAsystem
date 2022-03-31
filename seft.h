
#ifndef __MAIN
#define __MAIN

/***** #includes **************************************************************/

#include "util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "types.h"

#ifdef INC_TIMING
#include "timing.h"
#endif

/***** #defines and Macros ****************************************************/


#define MAX_QUERY_LEN       200
#define INIT_WORD_SIZE      10000
#define INCR_WORD_SIZE      1000
#define INIT_TERM_SIZE      100
#define INCR_TERM_SIZE      10
#define MAX_DOCS            100000
#define DEFAULT_WINDOW_SIZE 5
#define DEFAULT_MAX_WINDOWS 3
#define MAX_LINE_LENGTH     80
#define ASCII               256
#define ASCII7              128
#define MAX_WORD_LEN        16
#define WORD_SHIFT          4    // log2(MAX_WORD_LEN)
#define NOT_FOUND -1

/***** Data Structures ********************************************************/
typedef struct tnode *Tptr;
typedef struct tnode {
    char splitchar;

    Tptr lokid, eqkid, hikid;
    int term_index;
} Tnode;
Tptr root;

typedef struct 
    {
    int max_windows;
    char* file_name;
    char* query_string;
    long* seek_buffer;
    FILE* temp_file;
    char* doc_separator;
    FILE* query_file;
    int   window_size;
    bool  no_output;
    bool  no_hilite;
    bool  do_formfeed;
    int  stem_method;
    TERM  *query_table;
    WORD_SEFT *word_array;
    int no_words;
    int line_no;
    int min_length;
    int no_docs;
    int no_terms;
    int N;
    int max_words;
    int max_terms;
    long curr_pos;
    long *doc_idx;
    int* lookup;
    Tptr tst_root;
    } query_data;




/***** Function Prototypes ****************************************************/
void  process_args(int argc, char* argv[], query_data *qd);
void  init_qd(query_data* qd);
void  process_query_line(query_data* qd, char* line);
void  process_query_file(query_data* qd);
void  process_text_files(query_data* qd, FILE* fptr, char** filenameptr);
void  process_text(query_data* qd, long seek_pos, char** filenameptr, char* );
void  calc_weights(query_data* qd);
void  calc_accumulators(float (*shape)(long, int),query_data* qd);
void  selection(query_data* qd,char message[5][10000]);
float decay_circle(long, int);
void  usage(char* progname);


void output_window_header(WORD_SEFT*, int rank, int score,char*);
void output_sparse_window(query_data*, WORD_SEFT*,char* );
void output_null_window(query_data*, WORD_SEFT*);
void output_window(query_data*, WORD_SEFT*, int rank, int score,char* final);

int main_seft(int argch, char* argvh[],char message[10][10000]);


Tptr tst_insert(Tptr p, char *s, int);
void cleanup(Tptr p);
int tst_search(Tptr root, char *s);

/******************************************************************************/
#endif
