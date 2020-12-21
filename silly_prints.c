
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

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

//---------------------------------END
