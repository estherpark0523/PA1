/*
 * Filename: launchUserQuery.c
 * Author: N/A
 * UserId: N/A
 * Date: N/A
 * Sources of help: N/A
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "pa1.h"
#include "pa1Strings.h"

/*
 * Function Name: launchUserQuery
 * Function Prototype: void launchUserQuery( linkedListNode_t ** hashtbl );
 * Description: interactive search to allow user to search the tables
 * Parameters: hashtbl - pointer to the hashtable which will be queried
 * Side Effects: Output is printed to stdout
 * Return Value: None
 */ 
void launchUserQuery( linkedListNode_t ** hashtbl ){

  // Perform searching functionality
  char buf[BUFSIZ];
  printf( USER_PROMPT );

  // read input line by line
  while ( fgets( buf, BUFSIZ, stdin ) ) {
    // find and remove any newlines
    char * nlptr = strchr( buf, '\n' );
    if ( nlptr ) {
      *nlptr = '\0';
    }

    //if the user only pressed enter, nothing entered, dont search, reprompt
    if(buf[0] == '\0') {
      printf( USER_PROMPT );
      continue;
    }

    //lowercase the word
    int i;
    for( i = 0; i < strlen(buf); i++) {
      buf[i] = tolower(buf[i]);
    }

    // Look in the three tables to find how many collisions occurred
    int result = checkTable( buf, hashtbl );
    if ( result == 1 ) {
      printf( WORD_FOUND, buf );
    }
    else {
      printf( WORD_NOT_FOUND, buf );
    }
    printf( USER_PROMPT );
  }

  printf( "\n" );
}
