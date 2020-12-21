
//---------------------------------INFORMATION HEADER

/*
Title:         generic_prints.c
Project:       Fresh Prints
Description:   General-purpose print utilities

Author:        Aaron Van Cleave
Institution:   n/a

Date Modified: 20 Dec 2020
*/

//---------------------------------PREPROCESSOR DIRECTIVES

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "generic_prints.h"

//---------------------------------DISPLAY FUNCTIONS

int center_print(char * s, int n)
{
	if(s == NULL || n < 0)
	{
		return -1;
	}

	int l = strlen(s);

	int leftpad = 0;

	int rightpad = 0;

	if(n > l)
	{
		int padsize = (n - l)/2;

		leftpad += l + padsize;

		rightpad += (l % 2 == 0) ? padsize : (padsize + 1);
	}

	printf("\n--------------------<|%*s%*s|>--------------------\n\n", leftpad, s, -rightpad, "");

	return 0;
}

//---------------------------------TIMED FUNCTIONS

int timed_print(char * s, float f)
{
	if(s == NULL || f < 0)
  {
    return -1;
  }

  int l = strlen(s);

	int interval = (int)(f * 1000000);

	// Avoid division by 0: print nothing in f seconds
	if(l)
	{
		// Calculate time interval between each character in microseconds
		interval /= (l + 1);
	}

	usleep(interval);

	// Only function calls with nonzero-length strings enter here
	for(int i = 0; i < l; ++i)
  {
		printf("%c", s[i]);

		fflush(stdout);

		usleep(interval);
  }

	return 0;
}

//---------------------------------Z FUNCTIONS

//---------------------------------END
