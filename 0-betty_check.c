#include "shell.h"
/**
 * betty_check - function that passes the Betty checks
 * @argc: number of argument
 * @argv[]: name of file
 * Return: 0 or 1
 */
int betty_check(int argc, char *argv[])
{
	if (argc != 1)
	{
		printf("ERROR: usage ./betty %s",argv[1]);
		return (1);
	}
	else
	{
		system("./betty.sh argv[1]");
		return (0);
	}
}
