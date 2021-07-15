/*
 * Filename: spamFilter.c
 * Description: A function that contains the main driver of the spam-checking program. This function parses the approproate command line arguments, builds the hashtable of email data, and performs an interactive search.
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "pa1.h"
#include "pa1Strings.h"

int main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	// Parse command line arguments 
	linkedListNode_t ** hashtbl;
	FILE * file;

	// Handling the number of arguments
	if (argc == 1) {
		fprintf(stderr, LONG_USAGE);
		return 0;
	}

	if (argc != 2) {
		fprintf(stderr, INVALID_ARGS);
		fprintf(stderr, SHORT_USAGE);
		return 1;
	}


	file = fopen(argv[2], "r");

	// Handling infile errors
	if (file == NULL) {
		perror(FILTER_ERR);
		fclose(file);
		return 1;
	}


	// Initializing and populating the hashtable.
	hashtbl = newLinkedListArray(DEFAULT_SIZE);
	populateTable(hashtbl, file);

	// Perform an interactive search
	launchUserQuery(hashtbl);

	cleanup(hashtbl);

	fclose(file);
	

}
