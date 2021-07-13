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
#include "util.c"

int main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	char arg1, arg2;
	linkedListNode_t ** hashtbl;

	1. parse the command line arguments and process any errors;
	printf(USER_PROMPT);
	scanf("%d %d", &arg1, &arg2);

	if errors, {
		fprintf(stderr, SHORT_USAGE);
		return 0;
	}

	if (argc == 0 || argc > 3) {
		fprintf(stderr, INVALID_ARGS);
	}

	FILE * infile = fopen("spamFilter", "r");
		
	if (infile == NULL) {
		perror(FILTER_ERR);

	}
	2.
	populateTable(hashtbl, DEFAULT_SIZE);
	3.
	launchUserQuery(hashtbl);
	4.
	cleanup(hashtbl);

}
