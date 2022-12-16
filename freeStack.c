#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: head pointer to the stack
 *
 * Return: Nothing.
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * f_stack - prints at the top
 * @head: head of stack
 * @counter: line count
 *
 * Return: Nothing.
 */
void f_stack(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 0;
}
