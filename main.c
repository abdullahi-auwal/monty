#include "monty.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

stack_t *top = NULL;

/**
 * main - the main function for the monty interpreter
 * @argc: aruments' count
 * @argv: pointer to the arguments
 *
 * Return: 0 if sucessful.
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *opcode, *filename;
	char *argument;
	int value;
	unsigned int line_number;
	stack_t *stack;

	char *lineptr = NULL;
	size_t n = 0;
	int valid = -1;
	int val = -1;
	(void)top;

	if ((argc == 1) || (argc > 2))
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	filename = name_of_file(argv[1]);
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while (getline(&lineptr, &n, file) != -1)
	{
		opcode = strtok(lineptr, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		{
			line_number++;
			continue;
		}
		valid = check_opcode_valid(opcode);
		if (valid == 0)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			free(lineptr);
			free_stacks();
			fclose(file);
			exit(EXIT_FAILURE);
		}
		if (valid == 1)
		{
			argument = strtok(NULL, " \t\n");
			if (argument == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(lineptr);
				free_stacks();
				fclose(file);
				exit(EXIT_FAILURE);
			}
			value = atoi(argument);
			if (value == 0)
				val = check_zero(argument);
			else
				val = is_valid_number(argument);
			if (val == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				free(lineptr);
				free_stacks();
				fclose(file);
				exit(EXIT_FAILURE);
			}
			stack = malloc(sizeof(stack_t));
			if (stack == NULL)
			{
				fprintf(stderr, "Error: malloc failed\n");
				free(lineptr);
				free_stacks();
				fclose(file);
				exit(EXIT_FAILURE);
			}
			stack->n = value;
		}
		call_opcode_func(opcode, &stack, line_number);
		line_number++;
	}
	free(lineptr);
	free_stacks();
	fclose(file);
	return (0);
}


/**
 * check_opcode_valid - checks if the opcode is valid
 *	and which opcode it's
 * @opcode: the opcode
 *
 * Return: 0 if invalid opcode. other ints otherwise
 */
int check_opcode_valid(char *opcode)
{
	char *valid_funcs[] = {"push", "pall"};

	if (opcode != NULL)
	{
		if (strcmp(opcode, valid_funcs[0]) == 0)
			return (1);
		else if(strcmp(opcode, valid_funcs[1]) == 0)
			return (2);
	}

	return (0);
}

/**
 * check_zero - checks whether the zero returned is for error or an int zero
 * @argument: a string containing the zero
 *
 * Return: 0 if it is an error. 1 otherwise
 */
int check_zero(char *argument)
{
	if ((argument[0] == '0') && (argument[1] == '\0'))
		return (1);
	if ((argument[0] == '-') && (argument[2] == '\0'))
		return (1);
	return (0);
}

/**
 * call_opcode_func - calls the opcode function
 * @opcode: the opcode
 * @stack: pointer to the pointer to the stack
 * @line_number: the line count
 */
void call_opcode_func(char *opcode, stack_t **stack, unsigned int line_number)
{
	int i;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	i = 0;
	while (instructions[i].opcode != NULL)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			break;
		}
		i++;
	}
}
