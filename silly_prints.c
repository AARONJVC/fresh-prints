
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

int scream_print(char * s, float v0, float vf, int accel_i, int const_i)
{
  // String length
  int l = 0;

  if(s == NULL || !(l = strlen(s)) || v0 < 0 || vf < 0 || accel_i < 0 || const_i < 0)
  {
    return -1;
  }

  // Conversion to microseconds
  int v_usec = (int)(v0 * 1000000);
  int vf_usec = (int)(vf * 1000000);

  int delta = 0;

  //float prob_delta = 0;

  if(accel_i)
  {
    // The change to apply to v0 to accelerate it to vf in accel_i iterations
    delta = (vf_usec - v_usec) / accel_i;

    //prob_delta = 1.0 / accel_i;
  }

  //printf("V0: %i, VF: %i, PD: %i\n\n", v_usec, vf_usec, delta);

  float temp;

  const float prob_const = (float)v_usec / RAND_MAX;

  for(int i = 0; i < accel_i; ++i)
  {
    for(int j = 0; j < l; ++j)
    {
        // Randomly print the jth char of s as uppercase or lowercase
        temp = (float)rand() * prob_const;

        printf("%c", temp < v_usec ? s[j] : toupper(s[j]));

        fflush(stdout);

        usleep(v_usec);
    }

    // Prob increases at a constant rate
    //prob += prob_delta;

    // velocity changes at a constant rate
    v_usec += delta;
  }

  for(int i = 0; i < const_i; ++i)
  {
    for(int j = 0; j < l; ++j)
    {
        printf("%c", toupper(s[j]));

        fflush(stdout);

        usleep(vf_usec);
    }
  }

  return 0;
}

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

//---------------------------------END
