#include "main.h"
/**
* myenv_path - build a path for the command
* @avv : double pointer to arguments
* @aaa :  non-interactive double pointer to the arguments
* Return: int number of the status
*/
int myenv_path(char **avv, char **aaa)
{
	char *path = getenv("PATH");
	pid_t ii;
	int ll, sstatus;
	char *ccmd = NULL;

	if (!avv)
		return (EXIT_FAILURE);
	ccmd = mylocation(path, avv);
	if (!ccmd)
	{
		free(ccmd);
		myerror_msg(aaa, avv);
		return (127);
	}
	else
	{
		ii = fork();
		if (ii == -1)
		{
			free(ccmd);
			perror("Error");
			return (-2);
		}
		if (ii == 0)
		{
			if (execve(ccmd, avv, environ) == -1)
				sstatus = EXIT_FAILURE;
			exit(sstatus);
		}
		else
		{
			waitpid(ii, &ll, WUNTRACED);
			free(ccmd);
			if (WIFEXITED(ll))
				return (WEXITSTATUS(ll));
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_FAILURE);
}
/**
* myerror_msg - prints an error message
* @avv : double pointer to arguments
* @aaa :  non-interactive double pointer to the arguments
*/
void myerror_msg(char **aaa, char **avv)
{
	write(STDERR_FILENO, aaa[0], _strlen(aaa[0]));
	write(STDERR_FILENO, ": 1: ", _strlen(": 1: "));
	write(STDERR_FILENO, avv[0], _strlen(avv[0]));
	write(STDERR_FILENO, ": not found\n", _strlen(": not found\n"));
}
