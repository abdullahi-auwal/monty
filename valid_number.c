#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_valid_number - checks if its a valid number
 * @argument: the argument
 *
 * return: 0 if not valid
 */
int is_valid_number(char *argument)
{
	int i = 0;

	if (argument[i] == '-' || argument[i] == '+')
		i++;
	if (argument[i] == '\0')
		return (0);
	while (argument[i])
	{
		if (!isdigit((unsigned char)argument[i]))
			return (0);
		i++;
	}
	return (1);
}
