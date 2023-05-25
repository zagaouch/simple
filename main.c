#include "shell.h"

/**
 * main - execute the commende line
 * Return 0
 */
int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	printf("#cisfun$ ");
	fflush(stdout);

	while (fgets(command, sizeof(command), stdin))
	{
		command[strcspn(command, "\n")] = '\0';
		if (strlen(command) == 0)
		{
			printf("#cisfun$ ");
			fflush(stdout);
			continue;
		}
		shell_commande(command, NULL);
		printf("#cisfun$ ");
		fflush(stdout);
	}

	return 0;
}
