#include <stdio.h>
#include <unistd.h>

int main()
{
	char *b = NULL;
	size_t len = 0;
	int read;

	read = getline(&b, &len, stdin);
	write(STDOUT_FILENO, b, len);

}
