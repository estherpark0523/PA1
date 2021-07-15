/*
 * Filename: spamFilter.c
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

#define SINGLE_ARG 1
#define SECOND_ARG 2

/*
 * Function Name: main()
 * Function Prototype: int main(int argc, char* argv[]);
 * Description: A function that contains the main driver of the spam-checking program. This function parses th
 e approproate command line arguments, builds the hashtable of email data, and performs an interactive search.
 * Parameters: argc is an integer that represents the number of arguments pointed to by argv[]. argv[] is an a
 rray that points to the arguments passed.
 * Side Effects: The function reads in a datafile from parameter. The datafile is opened and read, then closed at the end of the program. Errors are printed to stderr. 
 * Error Conditions: If arguments are invalid or the number of arguments is incorrect, an error occurs. Additionally, if the file cannot be opened and read, a filter error occurs and is appropriately handled.
 * Return value: This main function returns either a 0 or 1 depending on overall program success. 0 indicates program success while 1 indicates errors that must be addressed.
 */

int main(int argc, char* argv[]);

int main(int argc, char* argv[]) {
	// Parse command line arguments 
	linkedListNode_t ** hashtbl;
	FILE * file;

	// Handling the number of arguments
	if (argc == SINGLE_ARG) {
		fprintf(stderr, LONG_USAGE);
		return 0;
	}

	if (argc != SECOND_ARG) {
		fprintf(stderr, INVALID_ARGS);
		fprintf(stderr, SHORT_USAGE);
		return 1;
	}


	file = fopen(argv[SECOND_ARG], "r");

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
