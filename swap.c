#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * swap - swaps the top two elements of the stack
 * @stack: no need for it
 * @line_number: the line number
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	(void)stack;
	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	tmp->n = top->n;
	top->n = top->next->n;
	top->next->n = tmp->n;
}
