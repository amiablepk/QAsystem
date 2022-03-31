/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         types.h
*
* Author:       Owen de Kretser (oldk@cs.mu.oz.au)
*
* Organisation: Dept. of CS&SE, University of Melbourne
*
* Date:         May 1999
*
* Purpose:      major data structures 
*
*******************************************************************************/

#ifndef __TYPES
#define __TYPES

/***** #includes **************************************************************/

#include <sys/types.h>

/***** Data Structures ********************************************************/

#ifndef u_char
#define u_char unsigned char
#endif

typedef struct term
    {
    u_char* Word;
    int fqt;
    int ft;
    float init_height;
    int   spread;
    int   term_num;
    } TERM;

typedef struct
    {
    unsigned long pos;
    float         level;
    TERM*         termptr;
    char**        name;
    int           line_no;
    int           no;
    long          seek_pos;
    } WORD_SEFT;


/******************************************************************************/

#endif
