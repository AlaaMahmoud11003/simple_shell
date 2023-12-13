#include "main.h"
/**
* main - the main function for the simple shell
* @avc : the number of arguments
* @avx : double pointer to the arguments
* Return: 0 in success
*/
int main(int avc, char **avx)
{
	char *cmdd = NULL;
	char **aaa;
	size_t ny = 0;
	ssize_t rr;
	int mm;
	(void)avc;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$) ", _strlen("$) "));
		rr = getline(&cmdd, &ny, stdin);
		if (rr == EOF)
		{
			free(cmdd);
			break;
		}
		rr = myno_arg(cmdd);
		if (rr != 0 && isatty(STDIN_FILENO) == 1)
		{
			mypars_cmd(cmdd, rr, &aaa);
			mm = mybu_path(aaa, avx);
			if (_strcmp(aaa[0], "exit") == 0 && myis_char(aaa[1]) == 0)
			{
				myfree_list(&aaa), free(cmdd), exit(mm);
			}
			myfree_list(&aaa);
		}
		if (isatty(STDIN_FILENO) == 0)
		{
			mypars_cmd(cmdd, rr, &aaa);
			mm = mybu_path(aaa, avx);
			if (aaa == NULL || mm >= 2)
			{
				myfree_list(&aaa), free(cmdd), exit(mm);
			}
			myfree_list(&aaa);
		}
	}
	return (0);
}
