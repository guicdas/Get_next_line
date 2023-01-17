#include <stdio.h>
#include <stdlib.h>

void func(char *s)
{
	while(*s)
	{
		printf("%d", *s);
		s++;
	}
}

int main()
{
	char *s = "ola";
	while(*s)
	{
		printf("%c\n", *s);
		func(s);
	}
		

}