#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * add - adds the top two elements of the stack
 * @stack: no need for it
 * @line_number: the line number
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (top == NULL || top->next == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	sum = top->n + top->next->n;
	pop(stack, line_number);
	top->n = sum;
}
