#include "monty.h"
#include <stdlib.h>

/**
 * free_stacks - free the stacks
 * @top: pointer to the top of the stack
 */
void free_stacks(stack_t *top)
{
	stack_t *tmp;

	while (top != NULL)
	{
		tmp = top;
		top = tmp->next;
		free(tmp);
	}
}
