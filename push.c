#include "monty.h"
#include <stddef.h>

/**
 * push - push an element unto a stack
 * @stack: the element
 * @line_number: the instruction line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (top == NULL)
	{
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
		top = *stack;
	}
	else
	{
		top->prev = *stack;
		(*stack)->next = top;
		(*stack)->prev = NULL;
		top = *stack;
	}
}
