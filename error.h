/*
 * defines for the error and message code.
 *
 * Copyright 1992 by Gray Watson and the Antaire Corporation
 *
 * This file is part of the malloc-debug package.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 * 
 * You should have received a copy of the GNU Library General Public
 * License along with this library (see COPYING-LIB); if not, write to the
 * Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 * 
 * The author of the program may be contacted at gray.watson@antaire.com
 *
 * $Id: error.h,v 1.4 1992/11/10 23:25:21 gray Exp $
 */

#ifndef __ERROR_H__
#define __ERROR_H__

#include <stdarg.h>			/* for ... */
#include "malloc.h"			/* for IMPORT */

/*
 * special debug codes which detail what debug features are enabled
 */

/* logging */
#define DEBUG_LOG_STATS		BIT_FLAG(0)	/* generally log statistics */
#define DEBUG_LOG_NONFREE	BIT_FLAG(1)	/* report non-freed pointers */
#define DEBUG_LOG_PERROR	BIT_FLAG(2)	/* log perror problems */
#define DEBUG_LOG_TRANS		BIT_FLAG(3)	/* log memory transactions */
#define DEBUG_LOG_BAD_POINTER	BIT_FLAG(4)	/* log pointer info on error */
#define DEBUG_LOG_ADMIN		BIT_FLAG(5)	/* log background admin info */

/* checking */
#define DEBUG_CHECK_FENCE	BIT_FLAG(10)	/* check fence-post errors  */
#define DEBUG_CHECK_HEAP	BIT_FLAG(11)	/* examine heap adm structs */
#define DEBUG_CHECK_LISTS	BIT_FLAG(12)	/* check the free lists */
#define DEBUG_CHECK_DBLOCK	BIT_FLAG(13)	/* closely examine dblocks */
#define DEBUG_DBLOCK_FENCE	BIT_FLAG(14)	/* check fences for dblocks */
#define DEBUG_CHECK_FREE	BIT_FLAG(15)	/* check free blocks of 0's */

/* misc */
#define DEBUG_REALLOC_COPY	BIT_FLAG(20)	/* copy all reallocations */
#define DEBUG_FREE_BLANK	BIT_FLAG(21)	/* write over free'd memory */
#define DEBUG_ERROR_ABORT	BIT_FLAG(22)	/* abort on error else exit */
#define DEBUG_ALLOC_BLANK	BIT_FLAG(23)	/* write over to-be-alloced */

/*
 * special flags that after being set or not/set and process start-up, cannot
 * be reset.
 */
#define DEBUG_NOT_CHANGEABLE	(DEBUG_CHECK_FREE)

/*<<<<<<<<<<  The below prototypes are auto-generated by fillproto */

/* global debug flags that are set my MALLOC_DEBUG environ variable */
IMPORT	int		_malloc_debug;

/*
 * message writer with printf like arguments
 */
IMPORT	void	_malloc_message(char * format, ...);

/*
 * kill the program because of an internal malloc error
 */
IMPORT	void	_malloc_die(void);

/*
 * malloc version of perror of an error in STR
 */
IMPORT	void	_malloc_perror(char * str);

/*<<<<<<<<<<   This is end of the auto-generated output from fillproto. */

#endif /* ! __ERROR_H__ */
