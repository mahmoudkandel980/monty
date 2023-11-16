#include "monty.h"
/**
* execute - executes the opcode
* @stack: head
* @counter: line counter
* @file: poiner to the monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{"nop", f_nop},
				{"sub", f_sub},
				{"div", f_div},
				{"mul", f_mul},
				{"mod", f_mod},
				{"pchar", f_pchar},
				{"pstr", f_pstr},
				{"rotl", f_rotl},
				{"rotr", f_rotr},
				{"queue", f_queue},
				{"stack", f_stack},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *opc;

	opc = strtok(content, " \n\t");
	if (opc && opc[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[j].opcode && opc)
	{
		if (strcmp(opc, opst[j].opcode) == 0)
		{	opst[j].f(stack, counter);
			return (0);
		}
		j++;
	}
	if (opc && opst[j].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, opc);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
