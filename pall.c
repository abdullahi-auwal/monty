#include "monty.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * pall - prints all the values on the stack
 * @stack: won't be used
 * @line_number: won't be used
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)stack;
	(void)line_number;
	tmp = top;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
