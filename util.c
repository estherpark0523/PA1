/* 
 * Filename: util.c
 * Author: John Li and Matthew Parker
 * UserId: N/A
 * Date: 6/21/20
 * Sources of help: our brains (and previously existing solution code)
 */


#include <stdlib.h>
#include <string.h>
#include "pa1.h"

/*
 * Name: newLinkedListNode
 * Function Prototype: linkedListNode_t * newLinkedList();
 * Description: Dynamically allocates memory for a linkedListNode_t struct
 *              and returns a pointer to the struct.
 * Parameters: None
 * Side Effects: None.
 * Error Conditions: None
 * Return Value: A pointer to the new struct.
 */
linkedListNode_t * newLinkedListNode(){
    linkedListNode_t * newHead = calloc( 1, sizeof( linkedListNode_t ) );
    if( ! newHead ){
        perror( MEM_ERR );
    }
    return newHead;
}

/*
 * Name: newLinkedListArray
 * Function Prototype: linkedListNode_t ** newLinkedListArray( int size );
 * Description: Dynamically allocates memory for an array of 
 *              linkedListNode_t double pointers (heads of linked lists) where
 *              the array's size is specified by the size parameter.
 * Parameters: size - The length of the array to be created.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: A pointer the the new array.
 */
linkedListNode_t ** newLinkedListArray( int size ){
    linkedListNode_t ** llArray = calloc( size, sizeof( linkedListNode_t * ) );
    if( ! llArray ){
        perror( MEM_ERR );
    }
    return llArray;
}

/* Name: strcp
 * Function Prototype: char * strcp( char * str );
 * Description: Returns a pointer to a new string which is a duplicate
 *              of the passed in string str. The new string is obtained
 *              with malloc.
 * Parameters: str - the string that will be duplicated.
 * Side Effects: None
 * Error Conditions: If the passed in string is not null terminated, the
 *                   behvaior is undefined.
 * Return Value: A pointer to the duplicated string.
 */
char * strcp( char * str ){
    int len = strlen( str ) + 1;
    char * newStr = malloc( len * sizeof( char ) );
    if ( ! newStr ) {
        perror( MEM_ERR );
    }
    else{
        strncpy( newStr, str, len );
    }
    return newStr;
}

/* Name: cleanup
 * Function Prototype: void cleanup( table_t * hashtbl );
 * Description: Frees the memory obtained by newLinkedListArray,
 *              newLinkedListNode, and strcp.
 * Parameters: hashtbl - the hashtbl whose memory will be freed.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: None
 */
void cleanup( linkedListNode_t ** hashtbl ){
    if ( hashtbl ) {
        for ( long i = 0; i < DEFAULT_SIZE; i++ ) {
            while ( hashtbl[i] ) {
                linkedListNode_t * llNode = hashtbl[i];
                hashtbl[i] = llNode->next;
                if ( llNode->value ) {
                    free( llNode->value );
                }
                free( llNode );
            }
        }
        free( hashtbl);
    }
}
