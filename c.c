#include "main.h"
/**
* myno_arg - counts the number of the arguments
* @ccmd : pointer to the input user
* Return: number of the arguments
*/
ssize_t myno_arg(char *ccmd)
{
	char *ccmd_c = NULL;
	char *ttoken = NULL;
	ssize_t nn = 0;


	ccmd_c = _strdup(ccmd);
	ttoken = _strtok(ccmd_c, TO_DEL);
	while (ttoken)
	{
		nn++;
		ttoken = _strtok(NULL, TO_DEL);
	}
	free(ccmd_c);
	return (n);
}
/**
* myis_char - checks for char
* @tt : pointer to the status
* Return: 0 in success
*/
int myis_char(char *tt)
{
	if (tt)
	{
		if (*tt >= 48 && *tt <= 57)
		{
			return (0);
		}
		if (*tt >= 65 && *tt <= 90)
		{
			return (1);
		}
		if (*tt >= 97 && *tt <= 122)
		{
			return (1);
		}
		if (_myatoi(tt) < 0)
		{
			return (1);
		}
	}
	return (0);
}
