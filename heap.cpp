/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         heap.c
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

/***** #includes **************************************************************/

#include "stdafx.h"
#include "heap.h"


/*******************************************************************************
*
* Function: heap_remove
*
* Purpose:  remove top element from a heap
*
*******************************************************************************/

WORD_SEFT*
heap_remove(WORD_SEFT** heap, int* size)
{
    WORD_SEFT* temp;

    temp = heap[1];
    heap[1] = heap[*size];

    (*size) -= 1;
    
    heap = heap_down(heap, 1, *size);

    return temp;
}

/*******************************************************************************
*
* Function: heap_down
*
* Purpose:  perform "downheap" operation on a heap
*
*******************************************************************************/

WORD_SEFT**
heap_down(WORD_SEFT** heap, int k, int N)
{
    WORD_SEFT* temp;
    int	      j;
    int div = N/2;

    temp = heap[k];

    while(k <= div)
        {
    	j = k+k;
	    if(j < N && heap[j]->level < heap[j+1]->level)
	        j++;
        if(temp->level >= heap[j]->level)
	        break;

        heap[k] = heap[j];
        k = j; 
        }
    heap[k] = temp;

    return heap;
}


/*******************************************************************************
*
* Function: heap_insert
*
* Purpose:  insert an element into a heap
*
*******************************************************************************/

WORD_SEFT** heap_insert(WORD_SEFT* newd, WORD_SEFT** heap, int i)
{
    heap[i] = newd;

	heap = heap_up(heap, i);

	return heap;
}

/*******************************************************************************
*
* Function: heap_up
*
* Purpose:  perform "upheap" operation on a heap
*
*******************************************************************************/

WORD_SEFT** heap_up(WORD_SEFT** heap, int k)
{
    WORD_SEFT* v;

    /* make a copy of newly inserted item */
    v = heap[k];

    /* while parent is less than inserted value move parent down */
    while(heap[k/2]->level <= v->level)
        {
        heap[k] = heap[k/2];
	    k = k/2;
        }

    /* now place inserted value at correct place in heap */
    heap[k] = v;

    return heap;
}

/******************************************************************************/

