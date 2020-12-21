
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
#include <string.h>
#include <time.h>
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

	// Seeding pseudorandom generation
	srand(time(0));

	center_print("WELCOME", 24);

	//timed_print("I'm a fast print\n", 2);

	//timed_print("I'm a slow print\n", 10);

	/*
	timed_print("", 2);

	timed_print("\n", 2);

	timed_print("A\n", 2);

	timed_print("AB\n", 2);

	timed_print("ABC\n", 2);

	timed_print("ABCD\n", 2);

	timed_print("ABCDE\n", 2);

	timed_print("ABCDEF\n", 2);

	timed_print("ABCDEFG\n", 2);

	timed_print("ABCDEFGH\n", 2);

	timed_print("ABCDEFGHI\n", 2);

	timed_print("ABCDEFGHIJ\n", 2);

	timed_print("ABCDEFGHIJK\n", 2);

	timed_print("ABCDEFGHIJKL\n", 2);

	timed_print("ABCDEFGHIJKLM\n", 2);

	timed_print("ABCDEFGHIJKLMN\n", 2);

	timed_print("", 0.0002);

	timed_print("\n", 0.0002);

	timed_print("A\n", 0.0002);

	timed_print("AB\n", 0.0002);

	timed_print("ABC\n", 0.0002);

	timed_print("ABCD\n", 0.0002);

	timed_print("ABCDE\n", 0.0002);

	timed_print("ABCDEF\n", 0.0002);

	timed_print("ABCDEFG\n", 0.0002);

	timed_print("ABCDEFGH\n", 0.0002);

	timed_print("ABCDEFGHI\n", 0.0002);

	timed_print("ABCDEFGHIJ\n", 0.0002);

	timed_print("ABCDEFGHIJK\n", 0.0002);

	timed_print("ABCDEFGHIJKL\n", 0.0002);

	timed_print("ABCDEFGHIJKLM\n", 0.0002);

	timed_print("ABCDEFGHIJKLMN\n", 0.0002);
	*/

	//timed_print("A long message printed in a short amount of time\n", 0.5);

	//timed_print("An even longer message printed in a disproportionately longer amount of time\n", 3);

	//sleepy_print("I'm sleepy\n", 0.1);

	scream_print("ouch", 0.25, 0.01, 0.5);

	scream_print("a", 0.5, 0.01, 0.5);

	//scream_print("ouch", 0.5, 0.00001, 0.999999);

	return EXIT_SUCCESS;
}

//---------------------------------FUNCTION DEFINITIONS

//----------X FUNCTIONS

//----------Y FUNCTIONS

//----------Z FUNCTIONS

//---------------------------------END
