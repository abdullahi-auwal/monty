#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pop - removes the top of the element of the stack
 * @stack: no need for it
 * @line_number: the line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void)stack;
	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = top;
	top = tmp->next;

	if (top != NULL)
		top->prev = NULL;
	free(tmp);
}
