
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

int scream_print(char * s, float d0, float df, int accel_i, int const_i)
{
  // String length
  int l = 0;

  if(s == NULL || !(l = strlen(s)) || d0 < 0 || df < 0 || accel_i < 0 || const_i < 0)
  {
    return -1;
  }

  // Conversion to microseconds
  int d_usec = (int)(d0 * 1000000);
  int df_usec = (int)(df * 1000000);

  int delta = 0;

  //float prob_delta = 0;

  if(accel_i)
  {
    // The change to apply to d0 to change it to df in accel_i iterations
    delta = (df_usec - d_usec) / accel_i;

    //prob_delta = 1.0 / accel_i;
  }

  //printf("D0: %i, DF: %i, PD: %i\n\n", d_usec, df_usec, delta);

  float temp;

  const float prob_const = (float)d_usec / RAND_MAX;

  for(int i = 0; i < accel_i; ++i)
  {
    for(int j = 0; j < l; ++j)
    {
        // Randomly print the jth char of s as uppercase or lowercase
        temp = (float)rand() * prob_const;

        printf("%c", temp < d_usec ? s[j] : toupper(s[j]));

        fflush(stdout);

        usleep(d_usec);
    }

    // Prob increases at a constant rate
    //prob += prob_delta;

    // delay changes at a constant rate
    d_usec += delta;
  }

  for(int i = 0; i < const_i; ++i)
  {
    for(int j = 0; j < l; ++j)
    {
        printf("%c", toupper(s[j]));

        fflush(stdout);

        usleep(df_usec);
    }
  }

  return 0;
}

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

//---------------------------------END
