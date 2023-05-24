#include "shell.h"
/**
 * shell_commande - function Display a prompt to type a command
 * @command: the command line
 */

void shell_commande(char *command)
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execlp(command, command, NULL);
		fprintf(stderr, "Command not found: %s\n", command);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		wait(NULL);
	else
	{
		fprintf(stderr, "ERROR: Fork failed\n");
		exit(EXIT_FAILURE);
	}
}
/**
 * main - the main funcion to call the fucnion fo excut the command
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "exit") == 0)
			break;
		shell_commande(command);
	}
	return (0);
}
