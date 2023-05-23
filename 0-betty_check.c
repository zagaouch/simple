#include "shell.h"
/**
 * main - function the search a file in your all folders
 * @argc: number of argument
 * @argv: name of file
 * Return: 0 or 1
 */
int main(int argc, char *argv[])
{
	char command[100];

	if (argc < 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	else
	{
		sprintf(command, "find / -name %s", argv[1]);
		system(command);
		return (0);
	}
}
