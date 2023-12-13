#include "main.h"
/**
* mypwdp - checks for the path
* @ccmd : pointer to the command
* Return: 0 in success 1 in failure
*/
int mypwdp(char *ccmd)
{
	int ii = 0;

	for (ii = 0; ccmd[ii] != '\0'; ii++)
	{
		if (ccmd[ii] == '/')
		{
			return (0);
		}
	}
	return (1);
}
/**
* mypars_cmd - build a path for the command
* @ccmd : pointer to the input user
* @rr : the number of the arguments
* @avv : pointer to a double pointer to the arguments
*/
void mypars_cmd(char *ccmd, ssize_t rr, char ***avv)
{
	char *ttoken;
	int ii = 0;
	int ll;
	*avv = malloc(sizeof(char *) * (rr + 1));
	if (!(*avv))
	{
		free(*avv);
		return;
	}
	ttoken = _strtok(ccmd, TO_DEL);
	while (ttoken)
	{
		(*avv)[ii] = malloc(sizeof(char) * (_strlen(ttoken) + 1));
		if (!(*avv)[ii])
		{
			ll = 0;
			while (ll < ii)
			{
				free((*avv)[ll]);
				ll++;
			}
			free(*avv);
			return;
		}
		_strcpy((*avv)[ii], ttoken);
		ttoken = _strtok(NULL, TO_DEL);
		ii++;
	}
	(*avv)[ii] = NULL;

}
