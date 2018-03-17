#include <stdlib.h>
#include <stdio.h>

char *_getenv(const char *name)
{
	extern char **environ;
	char *finder = NULL;
	int i = 0, j, len = 0;

	if (!name)
		return (NULL);
	else
	{
		while (name[len] != '\0')
			len++;

	}

	while (environ[i])
	{

		for (j = 0; j < len && *(environ[i] + j) != '\0'; j++)
		{
			if (name[j] != *(environ[i]+j))
				break;
			
			if (j == len - 1)
				return (environ[i] + j + 2);
		}

		i++;
	}

	return (NULL);

}

int main()
{
	
	printf("%s\n", _getenv("LANG"));

	printf("%s\n", _getenv("PWD"));
	
	printf("%s\n", _getenv("PATH"));

}
