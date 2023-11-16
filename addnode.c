#include "monty.h"
/**
 * addnode - add to the head stack a node
 * @head: head
 * @n: new value
 * Return: no return
*/
void addnode(stack_t **head, int n)
{

	stack_t *newNode, *x;

	x = *head;
	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{ printf("Error\n");
		exit(0); }
	if (x)
		x->prev = newNode;
	newNode->n = n;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}
