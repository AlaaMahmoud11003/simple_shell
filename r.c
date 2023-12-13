#include "main.h"
/**
* _myatoi - changes string into int
* @ccmd : pointer to the string
* Return: int and 0 in failure
*/
int _myatoi(const char *ccmd)
{
	int ll = 1;
	int rres = 0;

	if (*ccmd == '-')
	{
		ccmd++;
		ll = -1;
	}
	while (*ccmd != '\0')
	{
		if (*ccmd >= '0' && *ccmd <= '9')
		{
			rres = rres * 10 + (*ccmd - '0');
		}
		else
		{
			break;
		}
		ccmd++;
	}
	if (ll == -1)
	{
		return (rres * ll);
	}
	return (rres);
}
