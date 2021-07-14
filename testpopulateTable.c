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
#include <stdio.h>
#include <assert.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa1.h"

void testpopulateTable() {

  FILE * file;
  file = fopen("popTabTest.txt", "r");
  linkedListNode_t ** hashtbl;
  hashtbl = newLinkedListArray(5);
 
  populateTable(hashtbl, file);

  assert(checkTable("kitten@spam.me", hashtbl) == 1);


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
