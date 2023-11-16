#include "monty.h"
/**
 * f_div - divides the top two elements
 * @head: head
 * @counter: line number
 * Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int length = 0, x;

	h = *head;
	while (h)
	{
		h = h->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	x = h->next->n / h->n;
	h->next->n = x;
	*head = h->next;
	free(h);
}
