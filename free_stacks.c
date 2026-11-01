#include "monty.h"
#include <stdlib.h>

/**
 * free_stacks - free the stacks
 */
void free_stacks(char **lineptr, FILE *file)
{
	stack_t *tmp;

	while (top != NULL)
	{
		tmp = top;
		top = tmp->next;
		free(tmp);
	}
	top = NULL;

	free(*lineptr);
	fclose(file);
}
