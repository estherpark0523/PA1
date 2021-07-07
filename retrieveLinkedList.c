/*
 * Filename: retrieveLinkedList.c 
 * Description: A function that hashes the given string into the hash table. The function returns the element of the hashtable at the correctly assigned index.
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include "pa1.h"

linkedListNode_t *retrieveLinkedList(linkedListNode_t** hashtbl, char* string);

linkedListNode_t *retrieveLinkedList(linkedListNode_t** hashtbl, char* string) {
	int hashkey = hash(string) % size of hashtbl;
	return hashtbl[index];
}
