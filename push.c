#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: head
 * @counter: line number
 * Return: no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	int j, i = 0, f = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			i++;
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
				f = 1; }
		if (f == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	j = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, j);
	else
		addqueue(head, j);
}
