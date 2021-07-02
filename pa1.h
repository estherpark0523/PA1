/*
 * File: pa1.h
 * Description: Header file that contains function prototypes and
 *              constants.
 *
 * TODO Complete file header
 *
 * XXX Only add constants to this file at the bottom.
 * DO NOT EDIT FUNCTION PROTOTYPES OR PREDEFINED CONSTANTS
 *
 */

#ifndef PA1_H       /* Macro Guard */
#define PA1_H
#include <stdio.h>

typedef struct llist {
    struct llist * next;
    char * value;
} linkedListNode_t;

/* Hashing */
#define HASH_START_VAL 11
#define HASH_PRIME     37

/* Table Size */
#ifndef DEFAULT_SIZE
#define DEFAULT_SIZE 2003
#endif

/* Extra credit command line parsing */
#define FLAGS "si:h"
#define INFILE_FLAG 'i'
#define STATS_FLAG 's'
#define HELP_FLAG 'h'

// These macros combine to convert __LINE__ which is a number to a string,
// then the preprocessor concatenates all three to be file:lineNo for the 
// OOM perror call.
#define STR_HELP( x ) #x
#define MEM_ERR __FILE__ ":" STR_HELP( __LINE__ )

/* Utility Function Prototypes */
linkedListNode_t * newLinkedListNode();
linkedListNode_t ** newLinkedListArray( int size );
char * strcp( char * str );
void cleanup( linkedListNode_t ** hashtbl );

/* C Function Prototypes */
unsigned int hash( char * str );
void prependNode( linkedListNode_t ** head, char * str );
void llTableAddString( linkedListNode_t ** hashtbl, char *string );
void populateTable( linkedListNode_t ** hashtbl, FILE * dataFile );
linkedListNode_t * retrieveLinkedList( linkedListNode_t ** hashtbl, 
        char *string );
int checkTable( char * str, linkedListNode_t ** hashtbl );
void launchUserQuery( linkedListNode_t ** hashtbl );


#endif
