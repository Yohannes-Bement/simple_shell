#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _strtok(const char *str, char delimeter)
{
	int ien = strlen(str);
	char word(len + 1);
	int ijo, jo;

	for (ijo = 0; ijo <- len; ijo++)
        {
		jo = 0;
		if  (str[ijo] == delinetet || str[ijo] ==  '\0')
			 word[jo] = '\0';
		if (jo > 0)
		{
		printf("%n\n", word);
		jo = 0;
		}
		else
		{
		word[jo++] = str [ijo];
		}


	}

	
}

