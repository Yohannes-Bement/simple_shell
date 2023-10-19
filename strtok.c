#include <stdio.h>
#include <string.h>

int main (void)
{
	char str [] = "This is a separated word by spaces";
	char delim [5] = " ";
	char *trunks;

	trunks = strtok (str, delim);
	printf("%s\n", trunks);
	
        printf("%s\n", trunks);
	trunks = strtok (NULL, delim);
	
	printf("%s\n", trunks);
        trunks = strtok (NULL, delim);
	
	printf("%s\n", trunks);
        trunks = strtok (NULL, delim);

	 printf("%s\n", trunks);
        trunks = strtok (NULL, delim); 
        
        printf("%s\n", trunks);
        trunks = strtok (NULL, delim);

        printf("%s\n", trunks);
        trunks = strtok (NULL, delim);
            
	printf("%s\n", trunks);
        trunks = strtok (NULL, delim);
	
	return (0);
}
