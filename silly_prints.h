
//---------------------------------INFORMATION HEADER

/*
Title:         silly_prints.h
Project:       Fresh Prints
Description:   Fun and useless print functions

Author:        Aaron Van Cleave
Institution:   n/a

Date Modified: 21 Dec 2020
*/

//---------------------------------PREPROCESSOR DIRECTIVES

#ifndef HEADER_NAME_HERE
#define HEADER_NAME_HERE

#include <stdlib.h>
#include <stdio.h>

//---------------------------------DEFINITIONS

//---------------------------------STRUCTS

//---------------------------------TIMED FUNCTIONS

// Prints string s letter-by-letter, spaced apart, at intervals of f seconds
int sleepy_print(char * s, float f);

// Repeatedly prints string s letter-by-letter with initial delay d0 that changes to df over accel_i iterations
// Continues printing with delay df for const_i iterations
// Letters randomly capitalize with increasing probability during acceleration
// Letters are all capitalized during the constant speed print
int scream_print(char * s, float d0, float df, int accel_i, int const_i);

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

#endif

//---------------------------------END
