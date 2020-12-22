
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

#define MAX_STR_LEN 256
#define QUIT_COMMAND 'q'
#define HELP_COMMAND 'h'

//---------------------------------GLOBALS

// Arrays to store information about the available functions
char * g_generic[4] = {"Centered", "Timed", "Accelerated", NULL};
char * g_silly[3] = {"Sleepy", "Scream", NULL};

char ** g_all[3] = {g_generic, g_silly, NULL};

//---------------------------------FUNCTION DECLARATIONS

//----------USER INPUT FUNCTIONS

// Gets command line input from user
int get_input(char ** buffer);

// Validates a string from user
int validate_string(char * s);

// Validates a float from user
int validate_float(char * s, float * f);

// Validates an int from user
int validate_int(char * s, int * i);

// Validates a char from user
int validate_char(char * s, char * c);

//----------DISPLAY FUNCTIONS

void show_list();

//----------Z FUNCTIONS

//---------------------------------PROGRAM MAIN

int main(int argc, char * argv[])
{
	//------------------------------SECTION

	if(argc != 1)
	{
		printf("This program takes no arguments.\nUsage: %s\n", argv[0]);
		return EXIT_SUCCESS;
	}

	// Seeding pseudorandom generation
	srand(time(0));

	char user_command;

	center_print("WELCOME", 12);

	show_list();

	do
	{
		printf("\nTo test a function, enter its listed number.\n");
		printf("Enter a number, \"%c\" to see the list again, or \"%c\" to quit.\n", HELP_COMMAND, QUIT_COMMAND);
		printf(">>> ");

		char * buffer = NULL;

		int invalid = 1;

		while(invalid)
		{
			if(!get_input(&buffer))
			{
				if(!validate_char(buffer, &user_command))
				{
					invalid = 0;
				}
				free(buffer);
			}
		}

		switch(user_command)
		{
			case QUIT_COMMAND:
			{
				break;
			}
			case HELP_COMMAND:
			{
				printf("\n");
				show_list();
				break;
			}
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			{
				printf("\nFunction %c selected\n", user_command);
				break;
			}
			default:
			{
				printf("\nInvalid command\n");
				break;
			}
		}
	}
	while(user_command != QUIT_COMMAND);

	return EXIT_SUCCESS;
}

//---------------------------------FUNCTION DEFINITIONS

//----------USER INPUT FUNCTIONS

int get_input(char ** buffer)
{
	char * temp_buffer = NULL;

	size_t temp_size = 0;

	int status = -1;

	if(getline(&temp_buffer, &temp_size, stdin) != -1)
	{
		if((*buffer = (char *)malloc(MAX_STR_LEN * sizeof(char))) != NULL)
		{
			strncpy(*buffer, temp_buffer, (MAX_STR_LEN - 1));

			(*buffer)[MAX_STR_LEN - 1] = '\0';

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

//----------DISPLAY FUNCTIONS

void show_list()
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
}

//----------Z FUNCTIONS

//---------------------------------END
