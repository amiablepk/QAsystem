/**************************************************************************
 *
 * local_strings.h -- string routines
 * Copyright (C) 1994  Neil Sharman
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
 * $Id: local_strings.h,v 1.1 1997/09/02 09:17:24 wew Exp $
 *
 **************************************************************************/

#ifndef LOCAL_STRINGS_H
#define LOCAL_STRINGS_H

#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"

void string_copy(u_char* dest, u_char* src);
int arg_atoi(char *str);
int compare(u_char *s1, u_char *s2);
u_char *copy_string(u_char *src_str);
u_char *copy_string_tolower(u_char *src_str);
char * str255_to_string(u_char *str255, char *str);
u_char * string_to_str255(char *str, u_char *str255);
int prefixlen(u_char *s1, u_char *s2);
int cstr_prefixlen(u_char *s1, u_char *s2);
char *char2str(u_char c);
char *word2str(u_char* s);
char *de_escape_string(char *s);
void print_str255(u_char *str255, FILE *f);

#endif
