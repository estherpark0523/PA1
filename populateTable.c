/*
 * Filename: hash.c
 * Description: A function that will be used to create the hash key of a string.
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "pa1.h"

void populateTable(linkedListNode_t** hashtbl, FILE* dataFile);

void populateTable(linkedListNode_t** hashtbl, FILE* dataFile) {
	char buff[30];
	char converted[30];

	if (fgets(buff, 30, dataFile) != NULL) {
		char * pointer = strchr(buff, '\n');
		if (pointer != NULL) {
			*pointer = '\0';
		}
		
		for (int i = 0; i < 30; i++) {
			converted[i] = tolower(buff[i]);
		}

		llTableAddString(hashtbl, converted);
	}
		
}
