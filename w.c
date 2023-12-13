#include "main.h"
/**
* _strdup - dublicates a sring
* @cmd : pointer to a string
* Return: pointer to the dublicated string
*/
char *_strdup(char *cmd)
{
	char *cp;

	if (!cmd)

	{
		return (NULL);
	}
	cp = malloc((_strlen(cmd) + 1) * sizeof(char));
	if (!cp)
	{
		return (NULL);
	}
	_strcpy(cp, cmd);
	return (cp);
}
/**
* _strcpy - copies a string to another
* @des : pointer to a string
* @src : pointer to the source
* Return: pointer to the copied string
*/
char *_strcpy(char *des, char *src)
{
	char *a = src;

	while (*src != '\0')

	{
		*des++ = *src++;
	}
	*des = '\0';
	return (a);
}
/**
* _mygetenv - get a specific env variable
* @nname : pointer to the name of the variable
* Return: pointer to the variable
*/
char *_mygetenv(const char *nname)
{
	char *ee, *dd;
	char **een = environ;

	if (!nname)
	{
		return (NULL);
	}
	while (*een)
	{
		if (*een && _strcmp(*een, nname) == 0)
		{
			ee = _strchr(*een, "=");
			if (ee != NULL)
			{
				ee++;
				dd = malloc((_strlen(ee) + 1) * sizeof(char));
				if (dd != NULL)
				{
					_strcpy(dd, ee);
					return (dd);
				}
			}
		}
		een++;
	}
	return (NULL);
}
