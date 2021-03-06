/*
 * Filename: checkTable.c
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include <string.h>
#include "pa1.h"

/*
 * Function Name: checkTable()
 * Function Prototype: int checkTable(char* str, linkedListNode_t** hashtbl);
 * Description: A function that reports if the string already exists within the hashtable. This function calls upon retrieveLinkedList() to see if the hashtable contains the linked list and if the string exists in found linked list. 
 * Parameters: This function takes in a pointer to a char and a double pointer to a linked list node.
 * Side Effects: None
 * Error Conditions: None
 * Return value: The function returns 0 if the linked list does not exist or if the string does not exist within the linked list. The function returns 1 if the string is in the linked list at the correct value hashed using the given string.
 */

int checkTable(char* str, linkedListNode_t** hashtbl);

int checkTable(char* str, linkedListNode_t** hashtbl) {
	int len;
        len = strlen(str);
	linkedListNode_t * retrieved;
	retrieved = retrieveLinkedList(hashtbl, str);

	if ( retrieved ) {
		// if the input string is also found in the linked list,
		while ( retrieved != NULL) {
			int ret;
		        ret = strcmp(str, retrieved->value);
			if (ret == 0) {
				return 1;
			}
		}
	}

	return 0;
}
