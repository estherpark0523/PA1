/*
 * Filename: testhash
 * Author: TODO
 * Userid: TODO
 * Description: Unit test program to test the function hash().
 * Date: TODO
 * Sources of Help: TODO
 */

#include <string.h>
#include <stdlib.h>

#include "test.h"    /* For TEST() macro and stdio.h */
#include "pa1.h"

void testhash() {

  TEST( hash( "abc" ) == 693737 );
  TEST( hash( "paul" ) == 26452777 );

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
  fprintf( stderr, "Testing hash...\n\n" );
  testhash();
  fprintf( stderr, "\nDone running tests.\n" );
  return 0;
}
