#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
	char *b = NULL;
	size_t len = 0;
	
	getline(&b, &len, stdin);

	write(STDOUT_FILENO, b, len);
}
