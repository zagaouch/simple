#include "shell.h"
/**
 * shell_commande - function Display a prompt to type a command
 * @command: the command line
 * @envp: array of environment variables passed to the program
 */
void shell_commande(char *command, char *envp[])
{
	pid_t pid = fork();

	if (pid == 0)
	{
		char *argv[2];
		argv[0] = command;
		argv[1] = NULL;

		execve(command, argv, envp);
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

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("#cisfun$ ");
		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strlen(command) == 0)
			continue;
		shell_commande(command, NULL);
	}
	return (0);
}
