
//---------------------------------INFORMATION HEADER

/*
Title:         demo.c
Project:       Fresh Prints
Description:   An interactive demonstration of the print utilities

Author:        Aaron Van Cleave
Institution:   n/a

Date Modified: 20 Dec 2020
*/

//---------------------------------PREPROCESSOR DIRECTIVES

#include <stdlib.h>
#include <stdio.h>
#include "generic_prints.h"
#include "silly_prints.h"


//---------------------------------DEFINITIONS

//---------------------------------GLOBALS

//---------------------------------FUNCTION DECLARATIONS

//----------X FUNCTIONS

//----------Y FUNCTIONS

//----------Z FUNCTIONS

//---------------------------------PROGRAM MAIN

int main(int argc, char * argv[])
{
	//------------------------------SECTION

	center_print("WELCOME", 24);

	timed_print("I'm sleepy\n", 2);

	timed_print("I'm sleepy\n", 10);

	timed_print("A long message printed in a short amount of time\n", 0.5);

	return EXIT_SUCCESS;
}

//---------------------------------FUNCTION DEFINITIONS

//----------X FUNCTIONS

//----------Y FUNCTIONS

//----------Z FUNCTIONS

//---------------------------------END
