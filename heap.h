/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         heap.h
*
* Author:       Owen de Kretser (oldk@cs.mu.oz.au)
*
* Organisation: Dept. of CS&SE, University of Melbourne
*
* Date:         April 1999
*
* Purpose:      heap functions
*
*******************************************************************************/

#ifndef __HEAP
#define __HEAP

/***** #includes **************************************************************/

#include <stdio.h>
#include "types.h"

/***** Function Prototypes ****************************************************/

WORD_SEFT**      heap_insert(WORD_SEFT*, WORD_SEFT**, int);
WORD_SEFT**      heap_up(WORD_SEFT**, int);
WORD_SEFT*       heap_remove(WORD_SEFT**, int *);
WORD_SEFT**      heap_down(WORD_SEFT**, int, int);

/******************************************************************************/

#endif
