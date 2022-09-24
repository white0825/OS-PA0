/**********************************************************************
 * Copyright (c) 2021-2022
 *  Sang-Hoon Kim <sanghoonkim@ajou.ac.kr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTIABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 **********************************************************************/

/*====================================================================*/
/*          ****** DO NOT MODIFY ANYTHING FROM THIS LINE ******       */
#include <stdio.h>
#include "types.h"
#include "list_head.h"

/* Declaration for the queue instance defined in pa0.c */
extern struct list_head queue;

/* Entry for the queue */
struct entry {
	struct list_head list;
	char *string;
};
/*          ****** DO NOT MODIFY ANYTHING ABOVE THIS LINE ******      */
/*====================================================================*/

/*====================================================================*
 * The rest of this file is all yours. This implies that you can      *
 * include any header files if you want to ...                        */

#include <stdlib.h>                    /* like this */
#include <string.h>

/**
 * enqueue()
 *
 * DESCRIPTION
 *   Enqueue @string into the @queue. The @string should be inserted into the tail
 *   of the queue. You may use either the head or tail of the list for the head.
 */
void enqueue(char *string)
{
	struct entry *new=NULL;
	new=(struct entry*)malloc(sizeof(struct entry));

	int len=strlen(string);

	new->string=NULL;

	new->string=(char*)malloc(sizeof(char)*(len));

	strcpy(new->string, string);

	list_add_tail(&(new->list), &queue);

	//free(new->string);

	//free(new);
}


/**
 * dequeue()
 *
 * DESCRIPTION
 *   Dequeue a value from @queue and return it through @buffer. The value should
 *   come from the head of the queue, and the corresponding entry should be
 *   removed from @queue.
 *
 * RETURN
 *   If the queue is not empty, dequeue the head of @queue, and return 0
 *   If the queue is empty, return -1
 */
int dequeue(char *buffer)
{
	/* TODO: Implement this function */

	if(list_empty(&queue)){
		return -1;
	}
	else{
		struct entry *out=list_first_entry(&queue, struct entry, list);

		strcpy(buffer, out->string);

		free(out->string);

		list_del(&out->list);

		free(out);

		return 0;
	}
}


/**
 * dump_queue()
 *
 * DESCRIPTION
 *   Dump the contents in @queue. Print out @string of queue entries while
 *   traversing the queue from the head to the tail. Note that the value
 *   should be printed out to @stderr to get properly graded in pasubmit.
 */
void dump_queue(void)
{
	struct list_head *pos=NULL;
	struct entry *out=NULL;

	out=(struct entry*)malloc(sizeof(struct entry));

	list_for_each(pos, &queue){
		out=list_entry(pos, struct entry, list);
		fprintf(stderr, "%s\n", out->string);	
	}

	/* TODO: Implement this function */
}
