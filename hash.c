/*
 * Filename: hash.c
 * Description: A function that will be used to create the hash key of a string.
 * Author: Esther Park
 * Userid: cs30s121be
 * Date: 07/02/2021
 * Sources of help: None
 */


#include <stdio.h>
#include "pa1.h"

unsigned int hash(char* str);

unsigned int hash(char* str) {

	int hashVal = HASH_START_VAL;
	int len = strlen(str);

	for (i = 0; i < len; i = i + 2) {
		hashVal = (hashVal * HASH_PRIME) + (int) str[i];
	}

	for (i = 1; i < len; i = i + 2) {
		hashVal = (hashVal * HASH_PRIME) + (int) str[i];
	}
	return hashVal;
}
