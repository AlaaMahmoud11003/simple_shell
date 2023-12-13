#include "main.h"
/**
* mylocation - search for the command in the path
* @ppath : pointer to path
* @avv : double pointer to the command and arguments
* Return: pointer to the command full path
*/
char *mylocation(char *ppath, char **avv)
{
	char *ccmd = NULL;
	char *ppath_c = NULL;
	char *ttoken = NULL;

	if (ppath)
	{
		ppath_c = _strdup(ppath);
		if (!ppath_c)
		{
			free(ppath_c);
			return (NULL);
		}
		ttoken = _strtok(ppath_c, ":");
		while (ttoken)
		{
			ccmd = malloc((_strlen(ttoken) + _strlen(avv[0]) + 2) * sizeof(char));
			if (!ccmd)
			{
				free(ccmd), free(ppath_c);
				perror("Error");
				return (NULL);
			}
			_strcpy(ccmd, ttoken), _strcat(ccmd, "/"), _strcat(ccmd, avv[0]);
			if (access(ccmd, F_OK) == 0)
			{
				free(ppath_c);
				return (ccmd);
			}
			free(ccmd);
			ttoken = _strtok(NULL, ":");
		}
		free(ppath_c);
	}
	if (access(avv[0], F_OK) == 0)
	{
		if (mypwdp(avv[0]) == 0)
			return (_strdup(avv[0]));
	}
	return (NULL);
}
/**
* myfree_list - frees the memory after usage
* @avv :  pointer to a double pointer to the arguments
*/
void myfree_list(char ***avv)
{
	int dd = 0;

	while ((*avv)[dd] != NULL)

	{
		free((*avv)[dd]);
		dd++;
	}
	free((*avv));
}
