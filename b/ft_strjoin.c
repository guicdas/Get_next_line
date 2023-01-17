#include <stdlib.h>
#include <stdio.h>

char *ft_strjoin(char const *s1, char const *s2)
{
	unsigned char *str1;
	unsigned char *str2;
	unsigned char *str;
	int	i;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if((str = malloc(3)) != NULL){
        while(*str1){
			str[i++] = *str1;
			str1++;
		}
		while(*str2){
			str[i++] = *str2;
			str2++;
		}
		return((char *)str);
	}
	return (NULL);
}


int main(){
   char *ret;

   ret = ft_strjoin("eu tenho ", "medo");

   printf("String is - |%s|\n", ret);

}