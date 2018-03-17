#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *b = NULL; 
	size_t len = 0;
	int i = 0;
	const char delim[] = " ";
	char **p;
	char *token;
	pid_t childpid;
	char f[] = "fucked\n";

	
	p = malloc(10 * sizeof(char *));
	while (1)
	{
		getline(&b, &len, stdin);

		printf("Result of getline: %s\n", b);
		token = strtok(b, delim);
		p[i++] = token;
		printf("Token %s\n", token);

		while (token != NULL)
		{
			token = strtok(NULL, delim);
			p[i++] = token;
			printf("TOKEN: %s\n", token);
		}

		i = 0;
		while(p[i] != NULL)
		{
			printf("P array :%s: at position %d\n", p[i], i);
			i++;
		}

		childpid = fork();

		if (childpid == 0)
		{
			execve(p[0], p, NULL);
			write(STDOUT_FILENO,f,7);
		}
		else
			wait(NULL);
	}
	return (0);
}
