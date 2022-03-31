/**************************************************************************
 *
 * local_strings -- provides some extra string routines
 * Copyright (C) 1994  Authors
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 * $Id: local_strings.c,v 1.1 1997/09/02 09:17:24 wew Exp $
 *
 **************************************************************************/

#include "stdafx.h"
#include <sys/types.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "local_strings.h"
#include "util.h"

/* ===============================================================================
 * Function: compare
 * Description: Compare two strings. 
 * Input: Two binary strings, first byte of string indicates length. 
 * Output: Like standard strcmp.
 *	= 0 if s1 = s2
 *	< 0 if s1 < s2
 *	> 0 if s1 > s2
 * =============================================================================== */ 
int compare(u_char *s1, u_char *s2 )
{
  int l1= *s1, l2= *s2;
  int l = (l1<l2) ? l1 : l2;
  
  while (l--)
    if (*++s1 != *++s2)
      return( *s1 - *s2);
  return( l1 - l2 );
}

/* =========================================================================
 * Function: copy_string
 * Description: 
 *	Copies a string with the len in 1st byte
 * Input: 
 * Output: 
 * ========================================================================= */ 

u_char *copy_string(u_char *src_str)
{
    /*
  u_char *copy = safe_malloc((src_str[0]+1)*sizeof(u_char));

  fprintf(stderr,"Allocating %d\n",src_str[0]+1);
  if (!copy) return NULL;

  bcopy((char*)src_str, (char*)(copy), src_str[0]+1);
  return copy;
  */

  u_char *copy = (unsigned char*)safe_malloc((src_str[0]+1)*sizeof(u_char));
  int i=1;

  if (!copy) return NULL;

  copy[0] = src_str[0];
  while (i <= src_str[0])
    {
        copy[i] = src_str[i];
        i++;
    }
  return copy;

}

void 
string_copy(u_char* dest, u_char* src)
{

    int i=1;
        
    dest[0] = src[0];
    while (i <= src[0])
        {   
        dest[i] = src[i];
        i++;
        }
}


/* =========================================================================
 * Function: copy_string_tolower
 * Description: 
 *	Copies a string with the len in 1st byte (converts tolower)
 * Input: 
 * Output: 
 * ========================================================================= */ 

u_char *copy_string_tolower(u_char *src_str)
{
  u_char *copy =(unsigned char *) safe_malloc(src_str[0]+1);
  int i=1;

  if (!copy) return NULL;

  copy[0] = src_str[0];
  while (i <= src_str[0])
    {
        copy[i] = tolower(src_str[i]);
        i++;
    }

  return copy;

}


/* ===============================================================================
 * Function: char2str
 * Description: 
 * 	Ensures that non-printable characters are converted to a string
 * 	which is printable i.e. it indentifies the character.
 * 	e.g. carriage-return = "\n".
 * Input: character (may be non-printable)
 * Output: pointer to static string
 * =============================================================================== */ 

char *char2str(u_char c)
{
  static char buf[10];
  switch (c)
    {
    case '\n' :
      sprintf(buf, "\\n");
      break;
    case '\b' :
      sprintf(buf, "\\b");
      break;
    case '\f' :
      sprintf(buf, "\\f");
      break;
    case '\t' :
      sprintf(buf, "\\t");
      break;
    default:
      if (c >= ' ' && c <= 126)
	switch (c)
	  {
	  case '\\' :
	    sprintf(buf, "\\\\");
	    break;
	  case '\"' :
	    sprintf(buf, "\\\"");
	    break;
	  case '\'' :
	    sprintf(buf, "\\\'");
	    break;
	  default:
	    buf[0] = c;
	    buf[1] = '\0';
	    break;
	  }
      else
	sprintf(buf, "\\%03o", c);
      break;
    }
  return buf;
}

/* ===============================================================================
 * Function: word2str
 * Description: 
 *	Converts a string with possible non-printable characters into a string
 *	consisting entirely of printable characters.
 * Input: string, length stored in first byte
 * Output: pointer to static string
 * =============================================================================== */ 

char *word2str(u_char *s)
{
  static char buf[1024];
  char *p = buf;
  int i,len = (int) *s++;

  memset(buf, 0, sizeof(buf));
  for (i=0; i < len; i++)
    {
      strcpy(p, char2str(s[i]));
      p = strchr(p, '\0');
    }
  return buf;
}


/* =========================================================================
 * Function: de_escape_string
 * Description: 
 * 	Turn a string containing \ escapes into real characters
 * 	Note this destroys the string s in the process
 * Input: string to de-escape 
 * Output: the de-escaped string
 * ========================================================================= */ 
char *de_escape_string(char *s)
{
  char *org = s;
  char *d = s;
  while(*s)
    {
      if (*s == '\\')
	{
	  s++;
	  switch (*s++)
	    {
	    case '\0' : *d++ = '\\'; s--; break;
	    case '\\' : *d++ = '\\'; break;
	    case 'b'  : *d++ = '\b'; break;
	    case 'f'  : *d++ = '\f'; break;
	    case 'n'  : *d++ = '\n'; break;
	    case 'r'  : *d++ = '\r'; break;
	    case 't'  : *d++ = '\r'; break;
	    case '\"' : *d++ = '\"'; break;
	    case '\'' : *d++ = '\''; break;
	    case 'x'  : 
	      {
		int num = 0;
		if (isxdigit((int)*s))
		  {
		    char ch = toupper((int)*s++);
		    num = ch <='9' ? ch-'0' : ch - 'A' + 10;
		  }
		if (isxdigit((int)*s))
		  {
		    char ch = toupper((int)*s++);
		    num = (num << 4) + (ch <='9' ? ch-'0' : ch - 'A' + 10);
		  }
		*d++ = num;
		break;
	      }
	    case '0' :  case '1' :  case '2' :  case '3' :
	    case '4' :  case '5' :  case '6' :  case '7' :
	      {
		int num = *(s-1) - '0';
		if (*s >= '0' && *s <= '7')
		  num = (num << 3) + *s++ - '0';
		if (*s >= '0' && *s <= '7')
		  num = (num << 3) + *s++ - '0';
		*d++ = num;
		break;
	      }
	    }
	}
      else
	*d++ = *s++;
    }
  *d = '\0';
  return(org);
}

/* =========================================================================
 * Function: str255_to_string 
 * Description: 
 * Input: 
 * Output: 
 * ========================================================================= */ 

char *
str255_to_string(u_char *str255, char *str)
{
  static char buf[256];
  char *str_base = NULL;
  int len = *str255++; 
  int i = 0;

  /* if haven't been given a str to write to then use local buffer */
  if (!str)
    str = &(buf[0]);

  str_base = str;
  for (i = 0; i < len; i++)
    {
      *str++ = *str255++;
    }
  *str = '\0';

  return str_base;
}

/* =========================================================================
 * Function: string_to_str255
 * Description: 
 * Input: 
 * Output: 
 * ========================================================================= */ 

u_char *
string_to_str255(char *str, u_char *str255)
{
  static u_char buf[256];
  char *str_base = NULL;

  /* if haven't been given a str to write to then use local buffer */
  if (!str255)
    str255 = &(buf[0]);

  str_base =(char *)str255++; /* jump over length byte */

  {
    int i = 0;
    while(*str)
      {
	*str255++ = *str++;
	i++;
      }

    str_base[0] = i; /* fill in 1st byte length field */
  }

  return (unsigned char *)str_base;
}

/* =========================================================================
 * Function: print_str255
 * Description: 
 * Input: 
 * Output: 
 * ========================================================================= */ 

void 
print_str255(u_char *str255, FILE *f)
{
 //AfxMessageBox((char*)str255,MB_OK);
  int i = *str255++;
  while(i--)
    {
      fputc(*str255++, f);
    }
 //  fputc('', f);
 
 
}

