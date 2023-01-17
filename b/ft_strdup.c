#include <stdio.h>
#include <stdlib.h>

char *ft_strdup(const char *s)
{
	char *str;
	unsigned char * string;
	int tam;
	int	i;

	tam = 0;
	i = 0;
	string = (unsigned char *) s;
	while(*s){
		s++;
		tam++;
	}
	printf("%d \n",tam);
	if((str = malloc(sizeof(char) * tam * 2 + 1)) != NULL){
		while(*string){
			str[i] = *string;
			str[tam + i] = *string;
			i++;
			string++;
		}
		str[i + tam] = '\0';
		return ((char *) str);
	}
	return (NULL);
}

int main(){
    char *src = "boasd soueu";
    char *str;

    str = ft_strdup(src);

    printf("%s", str);
}