#include "monty.h"
#include <stdlib.h>

/**
 * free_stacks - free the stacks
 */
void free_stacks(void)
{
	stack_t *tmp;

	while (top != NULL)
	{
		tmp = top;
		top = tmp->next;
		free(tmp);
	}
	top = NULL;
}
