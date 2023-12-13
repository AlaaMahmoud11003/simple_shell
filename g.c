#include "main.h"
/**
* _strcat - concatenates to the end of a string
* @des : pointer to a string
* @src : pointer to the source
* Return: pointer to the copied string
*/
char *_strcat(char *des, char *src)
{
	char *a = des;

	while (*des)
	{
		des++;
	}
	while (*src)
	{
		*des++ = *src++;
	}
	*des = '\0';
	return (a);
}
/**
* _strchr - searches for a character in a string
* @des : pointer to a string we'll search in it
* @src : pointer to the character we'll search for
* Return: pointer to the character in the des string
*/
char *_strchr(const char *des, const char *src)
{
	while (*des)
	{
		if (*des == *src)
		{
			return ((char *)des);
		}
		des++;
	}
	return (NULL);
}
/**
* _strcmp - compares between two strings
* @cmd : pointer to a string
* @c : pointer to the second string
* Return: int number of the status
*/
int _strcmp(const char *cmd, const char *c)
{
	while (*cmd && *c)
	{
		if (*cmd != *c)
		{
			return (*cmd - *c);
		}
		cmd++;
		c++;
	}
	return (0);
}
