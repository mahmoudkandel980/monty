#include "monty.h"
/**
  *f_sub- sustration
  *@head: stack head
  *@counter: line number
  *Return: no return
 */
void f_sub(stack_t **head, unsigned int counter)
{
	stack_t *x;
	int sustration, nods;

	x = *head;
	for (nods = 0; x != NULL; nods++)
		x = x->next;
	if (nods < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	x = *head;
	sustration = x->next->n - x->n;
	x->next->n = sustration;
	*head = x->next;
	free(x);
}
