/********************************************************************************/
/* Copyright (c) 2004                                                           */
/* Daniel Sleator, David Temperley, and John Lafferty                           */
/* All rights reserved                                                          */
/*                                                                              */
/* Use of the link grammar parsing system is subject to the terms of the        */
/* Apache-style license set forth in the LICENSE file included with this        */ 
/* software, and also available at http://www.link.cs.cmu.edu/link/license.html */
/* This license allows free redistribution and use in source and binary forms,  */
/* with or without modification, subject to certain conditions.                 */
/*                                                                              */
/********************************************************************************/
pp_knowledge *pp_knowledge_open(char *dictname, char *path);
void pp_knowledge_close(pp_knowledge *knowledge);
