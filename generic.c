
//---------------------------------INFORMATION HEADER

/*
Title:         generic.c
Project:       Fresh Prints
Description:   General-purpose print utilities

Author:        Aaron Van Cleave
Institution:   n/a

Date Modified: 20 Dec 2020
*/

//---------------------------------PREPROCESSOR DIRECTIVES

#include <stdlib.h>
#include <stdio.h>
#include "generic.h"

//---------------------------------DISPLAY FUNCTIONS

void center_print(char * s, int n)
{
	int length = (int)strlen(s);

	int leftpad = 0;

	int rightpad = 0;

	if(n > length)
	{
		int padsize = (n - length)/2;

		leftpad += length + padsize;

		rightpad += (length % 2 == 0) ? padsize : (padsize + 1);
	}

	printf("\n--------------------<|%*s%*s|>--------------------\n\n", leftpad, s, -rightpad, "");
}

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

//---------------------------------END
