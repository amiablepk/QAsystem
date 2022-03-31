/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         util.h
*
* Author:       Owen de Kretser (oldk@cs.mu.oz.au)
*
* Organisation: Dept. of CS&SE, University of Melbourne
*
* Date:         April 1999
*
* Purpose:      General utility functions and #defines
*
*******************************************************************************/

#ifndef __UTIL
#define __UTIL

/***** #includes **************************************************************/

#include <stdio.h>

#ifdef INC_DMALLOC
#include <dmalloc.h>
#endif

/***** #defines and Macros ****************************************************/

#define bool  char
#define FALSE 0
#define TRUE  1

#define MAX_ERROR_MSG 100

/***** Function Prototypes ****************************************************/

void*   safe_malloc(size_t size);
void*   safe_realloc(void* p, size_t size);
char*   safe_strdup(const char* string);
FILE*   safe_fopen(char* filename, char* mode);
void    fatal_error(const char* messsage);

/******************************************************************************/

#endif
