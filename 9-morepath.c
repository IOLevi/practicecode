
#include <stdlib.h>
#include <stdio.h>

typedef struct direc{
	char *s;
	struct direc *next;

} PDIRECT

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
	char *path;
	char buf[1024];
	int i = 0, j = 0;
	char *token = NULL;
	char *delim = ":";
	PDIRECT *head;
	PDIRECT *temp;

	head = malloc(sizeof(PDIRECT));
	head->next = NULL;

	path = _getenv("PATH");

	token = strtok(path, delim);
	head->s = token;

	while(token != NULL)
	{
		token = strtok(NULL, delim);
		temp = malloc(sizeof(PDIRECT);
		temp->s = token;
		head->next = temp; 		
	}


}







