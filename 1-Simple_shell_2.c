#include "main.h"

/**
 * shell_commande - Executes the command with arguments using execvp.
 * @command: command The command to execute
 * @argumens: arguments An array of arguments for the command
 */
void shell_commande(char *command, char *arguments[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		execvp(command, arguments);
		fprintf(stderr, "Command not found: %s\n", command);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		fprintf(stderr, "ERROR: Fork failed\n");
		exit(EXIT_FAILURE);
	}
}
/*
 * main - execute a commnde
 * Return: 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *arguments[10];
	char *token;
	int i;

	while (1)
	{
		printf("#cisfun$ ");

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			continue;
		}

		token = strtok(command, " ");
		i = 0;

		while (token != NULL && i < MAX_ARGUMENTS - 1)
		{
			arguments[i++] = token;
			token = strtok(NULL, " ");
		}

		arguments[i] = NULL;

		shell_commande(arguments[0], arguments);
	}

	return (0);
}
