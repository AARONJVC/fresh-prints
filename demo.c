
//---------------------------------INFORMATION HEADER

/*
Title:         demo.c
Project:       Fresh Prints
Description:   An interactive demonstration of the print utilities

Author:        Aaron Van Cleave
Institution:   n/a

Date Modified: 21 Dec 2020
*/

//---------------------------------PREPROCESSOR DIRECTIVES

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "generic_prints.h"
#include "silly_prints.h"

//---------------------------------DEFINITIONS

#define MAX_STR_LEN 1024
#define QUIT_COMMAND 'q'

//---------------------------------GLOBALS

// Arrays to store information about the available functions
char * g_generic[4] = {"Centered", "Timed", "Accelerated", NULL};
char * g_silly[3] = {"Sleepy", "Scream", NULL};

char ** g_all[3] = {g_generic, g_silly, NULL};

//---------------------------------FUNCTION DECLARATIONS

//----------USER INPUT FUNCTIONS

// Gets command line input from user
int get_input(char * buffer);

// Validates a string from user
int validate_string(char * s);

// Validates a float from user
int validate_float(char * s, float * f);

// Validates an int from user
int validate_int(char * s, int * i);

// Validates a char from user
int validate_char(char * s, char * c);

//----------Y FUNCTIONS

//----------Z FUNCTIONS

//---------------------------------PROGRAM MAIN

int main(int argc, char * argv[])
{
	//------------------------------SECTION

	// Seeding pseudorandom generation
	srand(time(0));

	for(int i = 0; g_all[i] != NULL; ++i)
	{
		for(int j = 0; g_all[i][j] != NULL; ++j)
		{
			printf("%s\n", g_all[i][j]);
		}
	}

	center_print("WELCOME", 24);

	char user_command;

	do
	{
		int function_id = 0;

		for(int i = 0; g_all[i] != NULL; ++i)
		{
			for(int j = 0; g_all[i][j] != NULL; ++j)
			{
				printf("%2i - %s\n", function_id, g_all[i][j]);

				++function_id;
			}
		}

		printf("\nEnter the number of a function to test it: ");



		user_command = QUIT_COMMAND;
	}
	while(user_command != QUIT_COMMAND);






	/*
	center_print("WELCOME", 24);

	timed_print("I'm a fast print\n", 2);

	//timed_print("I'm a slow print\n", 10);


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


	timed_print("A long message printed in a short amount of time\n", 0.5);

	timed_print("An even longer message printed in a disproportionately longer amount of time\n", 5);

	sleepy_print("I'm sleepy\n", 0.1);

	scream_print("ouch", 0.25, 0.05, 10, 10);

	printf("\n");

	scream_print("a", 0.1, 0.01, 64, 128);

	printf("\n");

	scream_print("h", 0.1, 0.01, 64, 32);

	printf("\n");

	scream_print("a", 0.1, 0.01, 0, 32);

	printf("\n");

	scream_print("a", 0.1, 0.01, 32, 0);

	printf("\n");

	scream_print("a", 0.1, 0.3, 0, 32);

	printf("\n");

	scream_print("a", 0.1, 0.3, 32, 0);

	printf("\n");

	scream_print("a", 0.1, 0, 32, 0);

	accel_print("This line of text will print faster and faster over time\n", 0.1, 0.01);

	accel_print("This line of text will print slower and slower over time\n", 0.1, 0.5);

	accel_print("This line of text will print at a constant speed\n", 0.1, 0.1);

	accel_print("This line of text will print faster and faster over time\n", 0.1, 0.0001);
	*/

	return EXIT_SUCCESS;
}

//---------------------------------FUNCTION DEFINITIONS

//----------USER INPUT FUNCTIONS

int get_input(char * buffer)
{
	char * temp_buffer = NULL;

	size_t temp_size = 0;

	int status = -1;

	if(getline(&temp_buffer, &temp_size, stdin) != -1)
	{
		if((buffer = (char *)malloc(MAX_STR_LEN * sizeof(char))) != NULL)
		{
			strncpy(buffer, temp_buffer, (MAX_STR_LEN - 1));

			buffer[MAX_STR_LEN - 1] = '\0';

			status = 0;
		}
	}

	free(temp_buffer);

	return status;
}

int validate_string(char * s)
{
	return s == NULL ? -1 : 0;
}

int validate_float(char * s, float * f)
{
	if(s == NULL || !strlen(s))
	{
		return -1;
	}

	char * temp;

	float result = strtof(s, &temp);

	// Accept 0 when it is returned
	if(!result && strchr(s, '0') == NULL)
	{
		return -1;
	}

	*f = result;

	return 0;
}

int validate_int(char * s, int * i)
{
	if(s == NULL || !strlen(s))
	{
		return -1;
	}

	char * temp;

	int result = strtol(s, &temp, 10);

	// Accept 0 when it is returned
	if(!result && strchr(s, '0') == NULL)
	{
		return -1;
	}

	*i = result;

	return 0;
}

int validate_char(char * s, char * c)
{
	if(s == NULL || !strlen(s))
	{
		return -1;
	}

	*c = s[0];

	return 0;
}

//----------Y FUNCTIONS

//----------Z FUNCTIONS

//---------------------------------END
