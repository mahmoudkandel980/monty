#include "monty.h"
/**
 * f_queue - prints the top
 * @head: head
 * @counter: line number
 * Return: no return
*/
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - add node to the tail stack
 * @n: new value
 * @head: head
 * Return: no return
*/
void addqueue(stack_t **head, int n)
{
	stack_t *newNode, *x;

	x = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		printf("Error\n");
	}
	newNode->n = n;
	newNode->next = NULL;
	if (x)
	{
		while (x->next)
			x = x->next;
	}
	if (!x)
	{
		*head = newNode;
		newNode->prev = NULL;
	}
	else
	{
		x->next = newNode;
		newNode->prev = x;
	}
}
