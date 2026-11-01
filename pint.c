#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * pint - prints the value at the top of the stack
 * @stack: no need for it
 * @line_number: the line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)stack;

	if (top == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top->n);
}
