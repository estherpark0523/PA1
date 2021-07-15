/*
 * Filename: hash.c
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include "pa1.h"

/*
 * Function Name: hash()
 * Function Prototype: unsigned int hash(char* str);
 * Description: A function that will be used to create the hash key of a string.
 * Parameters: This function takes in str, which points to a char. This char will be hashed and converted.
 * Side Effects: None
 * Error Conditions: None
 * Return value: This function returns an integer, which is the char parameter's hashkey.
 */


unsigned int hash(char* str);

unsigned int hash(char* str) {

	int hashVal = HASH_START_VAL;
	int len = strlen(str);

	// For even indices
	for (int i = 0; i < len; i = i + 2) {
		hashVal = (hashVal * HASH_PRIME) + (int) str[i];
	}

	// For odd indices
	for (int j = 1; j < len; j = j + 2) {
		hashVal = (hashVal * HASH_PRIME) + (int) str[j];
	}
	return hashVal;
}
