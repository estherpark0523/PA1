/*
 * Filename: checkTable.c
 * Description: A function that reports if the string already exists within the hashtable. This function calls upon retrieveLinkedList() to see if the hashtable contains the linked list and if the string exists in found linked list. The function returns 0 if the linked list does not exist or if the string does not exist within the linked list. The function returns 1 if the string is in the linked list at the correct value hashed using the given string.
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include "pa1.h"

int checkTable(char* str, linkedListNode_t** hashtbl);

int checkTable(char* str, linkedListNode_t** hashtbl) {
	if (retrieveLinkedList(hashtbl, str) != NULL) {
		return 1;
	}
	return 0;
}