/*
 * Filename: llTableAddString.c
 * Description: A function that hashes the given hash string using the hash() function. Then, the element is hashed to the appropriate address in the hashtable.
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include "pa1.h"

void llTableAddString(linkedListNode_t** hashtbl, char* string);

void llTableAddString(linkedListNode_t** hashtbl, char* string) {
	int index = hash(string) % DEFAULT_SIZE;
	prependNode(*hashtbl[index]);
	return;
}

