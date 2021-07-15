/*
 * Filename: prependNode.c
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include "pa1.h"

/*
 * Function Name: prependNode()
 * Function Prototype: void prependNode(linkedListNode_t** head, char* str);
 * Description: A function that takes a pointer to the head of a linked list and aa string to insert, then pushes the element to the front of the linked list.
 * Parameters: This function takes in a double pointer to a linked list node head and a pointer to a string.
 * Side Effects: This function points a node head to a new node.
 * Error Conditions: None
 * Return value: void
 */

void prependNode(linkedListNode_t** head, char* str);

void prependNode(linkedListNode_t** head, char* str) {
	linkedListNode_t * newNode;
	newNode	= newLinkedListNode();
	newNode->value = strcp(str);
	newNode->next = *head;
	*head = newNode;

}
