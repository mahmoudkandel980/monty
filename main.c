#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: arguments number
* @argv:  location file
* Return: 0 (success)
*/
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t siz = 0;
	ssize_t readLine = 1;
	stack_t *stack = NULL;
	unsigned int bearor = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readLine > 0)
	{
		content = NULL;
		readLine = getline(&content, &siz, file);
		bus.content = content;
		bearor++;
		if (readLine > 0)
		{
			execute(content, &stack, bearor, file);
		}
		free(content);
	}
	free_stack(stack);
	fclose(file);
return (0);
}
