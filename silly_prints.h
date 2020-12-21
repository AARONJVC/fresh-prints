
//---------------------------------INFORMATION HEADER

/*
Title:         silly_prints.h
Project:       Fresh Prints
Description:   Fun and useless print functions

Author:        Aaron Van Cleave
Institution:   n/a

Date Modified: 20 Dec 2020
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

// Repeatedly prints string s at an initial speed v0 that accelerates to vf over accel_i iterations
// Continues printing at speed vf for const_i iterations
int scream_print(char * s, float v0, float vf, int accel_i, int const_i);

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

#endif

//---------------------------------END
