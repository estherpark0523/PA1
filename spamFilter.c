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
#include "util.c"

int main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	// Parse command line arguments 
	char * arg1;
	char * arg2;
	linkedListNode_t ** hashtbl;
	FILE * infile;

	printf(USER_PROMPT);
	scanf("%c %c", &(*arg1), &(*arg2));

	
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


	// Handling infile errors
	infile = fopen("spamFilter", "r");
	if (infile == NULL) {
		perror(FILTER_ERR);
		return 1;

	}

	// Initializing and populating the hashtable.
	hashtbl = newLinkedListArray(DEFAULT_SIZE);
	prependNode(hashtbl, arg1);
	hash(arg1);
	populateTable(hashtbl, infile);

	// Perform an interactive search
	launchUserQuery(hashtbl);

	cleanup(hashtbl);

	fclose(infile);

}
