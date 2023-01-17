#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	**ft_split(char const *s, char c)
{
	unsigned char *str1;
	char **str;
	int	i;
	int	j;

	i = 0;
	j = 0;
	str1 = (unsigned char *) s;
	if((str = malloc(3)) != NULL){
        while(*str1){
			if(*str1 != c){
				str[i][j] = *str1;
				j++;
			}else
			{
				j = 0;
				i++;
			}
			str++;
		}printf("sdf");
		return((char **)str);
	}printf("sdf");
	return (NULL);
}

int main(){
   char **ret;
   ret = ft_split("eu ,tenho, medo", ',');
   printf("String1 is - |%s|\nString2is - |%s|\nString3 is - |%s|\n", ret[1], ret[2], ret[3]);

}