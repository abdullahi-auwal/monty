#ifndef MONTY_H_
#define MONTY_H_

#define _GNU_SOURCE

/**
 * struct stack_s - doubly linked list representation of a stack (or a queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next elemnt of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *top;

int check_opcode_valid(char *opcode);
int check_zero(char *argument);
void call_opcode_func(char *opcode, stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
char *name_of_file(char *path);
void free_stacks(stack_t *top);
#endif /* MONTY_H_ */
