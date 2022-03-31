/*******************************************************************************
*
* Project:      seft (search engine for text)
*
* File:         words.h
*
* Author:       Owen de Kretser (oldk@cs.mu.oz.au)
*
* Organisation: Dept. of CS&SE, University of Melbourne
*
* Date:         April 1999
*
* Purpose:      word and non-word parsing macros
*
* Notes:        adapted from the code by Neil Sharman and Tim Shimmin
* 
*******************************************************************************/

/***** #includes **************************************************************/

#include <sys/types.h>
#include <ctype.h>

/***** #defines and Macros ****************************************************/

#define MAXWORDLEN	15
	/* Maximum length in bytes of any word or non-word. Note that
	   variations to MAXWORDLEN may have dramatic effects on the rest
	   of the program, as the length and the prefix match are packed
	   together into a four bit nibble, and there is not check that
	   this is possible, i.e., leave MAXWORDLEN alone... */
#define MAXSTEMLEN	255
	/* Maximum length in bytes of any stem. Note that
	   variations to MAXSTEMLEN may have dramatic effects on the rest
	   of the program, , i.e., leave MAXSTEMLEN alone... */
#define MAXNUMERIC	4
	/* Maximum number of numeric characters permitted in a word.
	   This avoids mg_long sequences of numbers creating just one
	   word occurrence for each number. At most 10,000 all numeric
	   words will be permitted. */

#define	INAWORD(c)	(isascii(c) && isalnum(c))
	/* The definition of what characters are permitted in a word
	*/

#define INNUMBER(c)     (isdigit(c)?1:0)


/*******************************************************************************
*
* Macro: PARSE_WORD
*
* Purpose: extract `pascal' word from text buffer
*
*******************************************************************************/

#define PARSE_WORD(Word, s_in, end)                      \
  do                                                          \
    {                                                         \
      register u_char  *wptr = (Word)+1;                      \
      register int    length = 0;                             \
      register int    c = *(s_in);                            \
                                                              \
      Word[2] = '\0'; \
      while ( INAWORD(c) && length < MAXSTEMLEN && (s_in)<=(end)) \
        {                                                     \
	  *wptr++ = (c);                                        \
	  length++;                                           \
	  c = *++(s_in);                                      \
	}                                                     \
      *(Word) = length;                                       \
    }while(0)                                                 

/*******************************************************************************
*
* Macro: PARSE_WORD_TOLOWER
*
* Purpose: extract `pascal' word from text buffer (characters tolower'd)
*
*******************************************************************************/

#define PARSE_WORD_TOLOWER(Word, s_in, end)                      \
  do                                                          \
    {                                                         \
      register u_char  *wptr = (Word)+1;                      \
      register int    length = 0;                             \
      register int    c = *(s_in);                            \
      register int    numeric = 0;                            \
                                                              \
      while ( length < MAXSTEMLEN && INAWORD(c) && (s_in)<=(end)) \
        {                                                     \
 	  if ((numeric += INNUMBER(c)) > MAXNUMERIC)          \
	    break;                                            \
	  *wptr++ = tolower(c);                                        \
	  length++;                                           \
	  c = *++(s_in);                                      \
	}                                                     \
      *(Word) = length;                                       \
    }while(0)                                                 

/*******************************************************************************
*
* Macro: PARSE_NON_WORD
*
* Purpose: extract `pascal' non-word from text buffer 
*
*******************************************************************************/

#define PARSE_NON_WORD(Word,s_in, end)           \
  do                                             \
    {                                            \
      register u_char  *wptr = (Word)+1;                      \
      register int    length = 0;                             \
      register int    c = *(s_in);                            \
      while (!INAWORD(c) && (s_in)<=(end)) \
        {                                                     \
	  *wptr++ = c;                                        \
	  length++;                                           \
	  c = *++(s_in);                                      \
	}                                                     \
      *(Word) = length;                                       \
    }while(0)                                                 

/*******************************************************************************
*
* Macro: PARSE_NON_WORD
*
* Purpose: parse `pascal' non-word from text buffer, discard word
*
*******************************************************************************/

#define PARSE_NON_WORD_DISCARD(s_in, end)           \
  do                                             \
    {                                            \
      while (!INAWORD(*(s_in)) && (s_in)<=(end)) \
	(s_in)++;                                \
    }while(0)                              

/*******************************************************************************
*
* Macro: PARSE_NON_WORD_FLAG
*
* Purpose: parse non-word from text buffer, discard word, check for ^B
*
*******************************************************************************/

#define PARSE_NON_WORD_FLAG(flag,s_in, end)           \
  do                                             \
    {                                            \
      flag = 0; \
      while (!INAWORD(*(s_in)) && (s_in)<=(end)) \
      { \
        if (*(s_in) == '\002') \
            flag = 1; \
	    (s_in)++;                                \
      } \
    }while(0)                              

