
//---------------------------------INFORMATION HEADER

/*
Title:         generic_prints.h
Project:       Fresh Prints
Description:   General-purpose print utilities

Author:        Aaron Van Cleave
Institution:   n/a

Date Modified: 21 Dec 2020
*/

//---------------------------------PREPROCESSOR DIRECTIVES

#ifndef GENERIC_PRINT_UTILS
#define GENERIC_PRINT_UTILS

#include <stdlib.h>
#include <stdio.h>

//---------------------------------DEFINITIONS

//---------------------------------STRUCTS

//---------------------------------DISPLAY FUNCTIONS

// A centered header of n char spaces or the length of string s, whichever is longer
int center_print(char * s, int n);

//---------------------------------TIMED FUNCTIONS

// Prints string s letter-by-letter at equal intervals within at least f seconds
int timed_print(char * s, float f);

// Prints string s letter-by-letter with a delay that changes from d0 to df
int accel_print(char * s, float d0, float df);

//---------------------------------Z FUNCTIONS

#endif

//---------------------------------END
