#include "main.h"
/**
 * mmy_cd - function that changes the working current shell executon
 * @aarcgs: arcgs
 * Return: -1 .
 */
int mmy_cd(char **aarcgs)
{
	if (aarcgs[1] == NULL)
	{
		perror("Error");
	}
	else
	{
		if (chdir(aarcgs[1]) != 0)
		{
			perror("Error in cd: changing the dir\n");
		}
	}
	return (0);
}
/**
 * mmy_env - function that prints enviroment variables
 * @aarcgs: arcgs
 * Return: -1
 */
int mmy_env(char **aarcgs)
{
	int gg = 0;
	(void)(**aarcgs);

	while (environ[gg] != NULL)
	{
		write(STDOUT_FILENO, environ[gg], _strlen(environ[gg]));
		write(STDOUT_FILENO, "\n", 1);
		gg++;
	}
	return (0);
}
/**
 * mmy_exit - function that couses normal process termin
 * @aarcgs: arcgs
 * Return: 0
 */
int mmy_exit(char **aarcgs)
{
	if (aarcgs[1])
	{
		if (_myatoi(aarcgs[1]) < 0 || (*aarcgs[1] < 48 || *aarcgs[1] > 57))
		{
			write(STDERR_FILENO, "./hsh: 1: ", _strlen("./hsh: 1: "));
			write(STDERR_FILENO, "exit: ", _strlen("exit: "));
			write(STDERR_FILENO, "Illegal number: ", _strlen("Illegal number: "));
			write(STDERR_FILENO, aarcgs[1], _strlen(aarcgs[1]));
			write(STDERR_FILENO, "\n", 1);
			return (2);
		}
		return (_myatoi(aarcgs[1]));
	}
	else
	{
		return (0);
	}
}
/**
* mybu_path - checks if the command built-in
* @avv : double pointer to arguments
* @aaa : non-interactive double pointer to the arguments
* Return: int number of the status
*/
int mybu_path(char **avv, char **aaa)
{
	int ii;
	char *builti[4] = {"cd", "env", "exit", NULL};

	int (*builtinex[])(char **) = {
		&mmy_cd,
		&mmy_env,
		&mmy_exit,
		NULL
	};
	if (!avv || avv[0] == NULL)
	{
		return (-1);
	}
	ii = 0;
	while (builti[ii] != NULL)
	{
		if (_strcmp(builti[ii], avv[0]) == 0)
		{
			return ((*builtinex[ii])(avv));
		}
		ii++;
	}
	return (myenv_path(avv, aaa));
}
