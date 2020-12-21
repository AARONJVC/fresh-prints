
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

// Repeatedly prints string s at an initial speed v0 that accelerates at acc
// Capitalization is randomized but becomes more likely over time according to prob
int scream_print(char * s, float v0, float acc, float prob);

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

#endif

//---------------------------------END
