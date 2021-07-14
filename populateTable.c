/*
 * Filename: populateTable.c
 * Description: A function that populates the hashtable by reading in the dataFile, grabbing each line, and adding each email address string to the table.
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
	int len = strlen(buff);

	while (fgets(buff, 30, dataFile) != NULL) {
		// Find and remove newline characters by replacing them with a null character.
		char * pointer = strchr(buff, '\n');
		if ( pointer ) {
			*pointer = '\0';
		}
		
		// To account for case-sensitivity, lowercase every character of the string.
		for (int i = 0; i < len; i++) {
			buff[i] = tolower(buff[i]);
		}

		llTableAddString(hashtbl, buff);
	}
		
}
