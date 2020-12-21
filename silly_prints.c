
//---------------------------------INFORMATION HEADER

/*
Title:         silly_prints.c
Project:       Fresh Prints
Description:   Fun and useless print functions

Author:        Aaron Van Cleave
Institution:   n/a

Date Modified: 20 Dec 2020
*/

//---------------------------------PREPROCESSOR DIRECTIVES

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "silly_prints.h"

//---------------------------------TIMED FUNCTIONS

int sleepy_print(char * s, float f)
{
  if(s == NULL || f < 0)
  {
    return -1;
  }

  int l = strlen(s);

  int interval = f * 1000000;

  for(int i = 0; i < l; ++i)
  {
		usleep(interval);

		printf("%c ", s[i]);

		fflush(stdout);
  }

	return 0;
}

int scream_print(char * s, float v0, float acc, float prob)
{
  // String length
  int l = 0;

  if(s == NULL || !(l = strlen(s)) || v0 < 0 || acc <= 0 || prob < 0 || prob > 1)
  {
    return -1;
  }

  // Conversion to microseconds
  int delay = (int)(v0 * 1000000);
  int acc_unit = (int)(acc * 1000000);

  // Number of iterations to execute
  // Enough that the delay will approach 0
  int iters = delay / acc_unit;

  float temp;

  for(int i = 0; i < iters; ++i)
  {
    for(int j = 0; j < l; ++j)
    {
        // Randomly print the jth char of s as uppercase or lowercase
        temp = (float)rand() / RAND_MAX;

        printf("%c", temp < prob ? s[j] : toupper(s[j]));

        fflush(stdout);

        usleep(delay);
    }

    // Prob gradually decreases to make uppercase more likely
    prob *= prob;

    // Delay decreases at a constant rate
    delay -= acc_unit;
  }

  printf("\n");

  return 0;
}

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

//---------------------------------END
