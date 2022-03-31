/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         hash.h
*
* Author:       Owen de Kretser (oldk@cs.mu.oz.au)
*
* Organisation: Dept. of CS&SE, University of Melbourne
*
* Date:         April 1999
*
* Purpose:      hash table functions
*
*******************************************************************************/

#ifndef __HASH
#define __HASH

/***** #includes **************************************************************/

#include <sys/types.h>
#include "types.h"

/***** #defines and Macros ****************************************************/

#define HASH_SIZE 31429 

/***** Data Structures ********************************************************/

typedef struct llist         /* linked-list for separate chaining */
    {
    TERM term;
    struct llist* next;
    } LLIST;

typedef LLIST** HASH;

/***** Function Prototypes ****************************************************/

void   hash_init(HASH* hash_table);
unsigned int  hash(u_char* Word);
void   hash_insert(HASH* hash_table, u_char* Word, int* no_terms);
void   list_insert(LLIST** hash_entry, u_char* Word, int* no_terms);
LLIST* hash_lookup(LLIST** hash_table, u_char* Word);

/******************************************************************************/

#endif
