#include "shell.h"

/**
 * main - prompt function
 * Return 0
 */
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
