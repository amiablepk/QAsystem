/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         util.c
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

/***** #includes **************************************************************/

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include "util.h"

/*******************************************************************************
*
* Function: safe_malloc
*
* Purpose:  safe version of malloc (error message and exit on failure)
*
*******************************************************************************/

void*
safe_malloc(size_t size)
{
    register void *mem;

    mem = malloc(size);

        //fprintf(stderr,"Trying to allocated %d\n",size);
    if ((mem == NULL) && (size != 0)) 
        {
        fatal_error("Out of memory in safe_malloc");
        }

    return (mem);
}

/*******************************************************************************
*
* Function: safe_realloc
*
* Purpose:  safe version of realloc (error message and exit on failure)
*
*******************************************************************************/


void*
safe_realloc(void* p, size_t size)
{
    register void *mem;
    
    mem = realloc(p,size);

    if ((mem == NULL) && (size != 0)) 
        {
        fatal_error("Out of memory in safe_realloc");
        }

    return (mem);
}

/*******************************************************************************
*
* Function: safe_strdup
*
* Purpose:  safe version of strdup (error message and exit on failure)
*
*******************************************************************************/

char*
safe_strdup(const char* string)
{
    char* copy;

    copy = strdup(string);

    if (copy == NULL)
        {
        fatal_error("Out of memory in safe_strdup");
        }

    return (copy);
}

/*******************************************************************************
*
* Function: safe_fopen
*
* Purpose:  safe version of fopen (error message and exit on failure)
*
*******************************************************************************/

FILE*
safe_fopen(char* filename, char* mode)
{
    FILE* file_ptr;
    char  error_msg[MAX_ERROR_MSG];

    if ((file_ptr = fopen(filename,mode)) == NULL)
        {
        sprintf(error_msg,"Could not open file %s",filename);
        fatal_error(error_msg);
        }

    return (file_ptr);
}


/*******************************************************************************
*
* Function: fatal_error
*
* Purpose:  print error message to stderr and exit
*
*******************************************************************************/

void
fatal_error(const char* message)
{
    fprintf(stderr,"%s\n", message);

    exit(1);
}

/******************************************************************************/
