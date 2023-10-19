#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	size_t n = 10;
	char *buf = NULL;

	printf("root@85484818$");
	getline(&buf, &n, stdin);
	printf(" %s", buf);
	

	free(buf);

	return (0);
}
