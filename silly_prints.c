
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

void sleepy_print(char * s, float f)
{
  if(s == NULL )
  {
    return;
  }

  int l = strlen(s);

  for(int i = 0; i < l; i++)
  {
    printf("%c", s[i]);

    sleep(f);
  }

  printf("\n");
}

//---------------------------------Y FUNCTIONS

//---------------------------------Z FUNCTIONS

//---------------------------------END
