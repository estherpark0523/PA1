/*
 * Filename: testpopulateTable.c
 * Author: Esther Park
 * Userid: cs30s121be
 * Description: Unit test program to test the function populateTable().
 * Date: 07/12/2021
 * Sources of Help: none
 */

#include <string.h>
#include <stdlib.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa1.h"

void testpopulateTable() {

  //TEST( hash( "abc" ) == 693737 );
  //TEST( hash( "paul" ) == 26452777 );
  FILE * file = fopen(&1, "r");
  linkedListNode_t ** hashtbl;
  hashtbl = newLinkedListArray(50);
 

  populateTable(hashtbl, file);


}

/* 
 * Function Name: main()
 * Function prototype: int main();
 * Description: The test driver. Runs specified tests.
 * Side Effects: None
 * Error Conditions: None
 * Return Value: 0 on exit success.
 */
int main() {
  fprintf( stderr, "Testing populateTable...\n\n" );
  testpopulateTable();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
