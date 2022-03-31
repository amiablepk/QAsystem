/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         hash.c
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

/***** #includes **************************************************************/

#include "stdafx.h"
#include <string.h>
#include "hash.h"
#include "util.h"
#include "local_strings.h"

/*******************************************************************************
*
* Function: hash_init
*
* Purpose:  dynamically allocate memory for hash table (of size HASH_SIZE)
*
*******************************************************************************/

void
hash_init(HASH* hash_table)
{
    int i;

    *hash_table = (LLIST**)safe_malloc(HASH_SIZE*sizeof(LLIST*));

    for (i=0; i < HASH_SIZE; i++)
        {
        (*hash_table)[i] = NULL;
        }
}

/*******************************************************************************
*
* Function: hash
*
* Purpose:  calculate the hash key corresponding to a given subject code
*
*******************************************************************************/

unsigned int
hash(u_char* Word)
{
    int h=0;
    int i;
    int length = *Word;
    
    for (i=1; i <= length; i++) 
        {
        h = ((h<<6) + Word[i]) % HASH_SIZE;
        }

    return (h);
}

/*******************************************************************************
*
* Function: hash_insert
*
* Purpose:  insert data item into hash table (uses separate chaining)
*
*******************************************************************************/

void
hash_insert(HASH* hash_table, u_char* Word, int* no_terms)
{
    int key = hash(Word);                         

    list_insert(&((*hash_table)[key]), Word, no_terms);    
}

/*******************************************************************************
*
* Function: list_insert
*
* Purpose:  insert data item into sorted linked list 
*
*******************************************************************************/

void
list_insert(LLIST** hash_entry, u_char* Word, int* no_terms)
{
    LLIST* new_node;
    LLIST* curr  = *hash_entry;
    LLIST* prev  = curr;

    new_node = (LLIST*)safe_malloc(sizeof(LLIST));
    
    (*no_terms)++;
    new_node->term.Word = copy_string(Word);
    new_node->term.fqt = 1;
    new_node->term.ft = 0;
    new_node->term.term_num = *no_terms;
    new_node->next = NULL;
        
    if (*hash_entry == NULL)                /* first entry */
        {
        *hash_entry = new_node;
        }
    else                                    /* insert */
        {
        while ((curr) && (compare(curr->term.Word,Word) > 0))
            {
            prev = curr;
            curr = curr->next;
            }
        if (curr == NULL)
            {
            prev->next = new_node;
            }
        else if (compare(curr->term.Word,Word) == 0)
            {
            curr->term.fqt++;
            (*no_terms)--;
            free(new_node->term.Word);
            free(new_node);
            }
        else if (*hash_entry == curr)
            {
            new_node->next = curr;
            *hash_entry = new_node;
            }
        else
            {
            prev->next = new_node;
            new_node->next = curr;
            }
        }
}

/*******************************************************************************
*
* Function: hash_lookup
*
* Purpose:  lookup up given data item in hash table
*
*******************************************************************************/

LLIST*
hash_lookup(LLIST** hash_table, u_char* Word)
{
    int key; 
    LLIST* curr;
    int cmp;

    key  = hash(Word);

    curr = hash_table[key];
    
    while ((curr != NULL) && ((cmp=compare(curr->term.Word,Word)) > 0))
        {
        curr = curr->next;
        }
    if (curr == NULL)
        {
        return (NULL);
        }
    else if (cmp == 0)
        {
        return (curr);
        }
    else
        {
        return (NULL);
        }
}
