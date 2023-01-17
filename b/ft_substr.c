#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;
	unsigned char * comp;
	size_t j;

	j = 0;
	comp = (unsigned char *) s;
	if((str = malloc(3)) != NULL){
		while(*comp){
			if(*comp == start){
				while(j < len){
					str[j++] = *comp++;
				}
				return ((char *)str);
			}
			comp++;
		}
	}
	return (NULL);
}

int main(){
   char *ret;

   ret = ft_substr("eu tenho medo", 'm', 3);

   printf("String is - |%s|\n", ret);

	free(str);
}