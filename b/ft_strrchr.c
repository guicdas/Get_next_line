
#include <stdio.h>
#include <string.h>

char *ft_strrchr(const char *str, int c){
	int i;

	while(*str){
		str++;
		i++;
	}
	while(i != 0){
		if (*str == c){
			return ((char *)str);
		}
		str--;
		i--;
	}
	return (NULL);
}

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;
   char * yert;

   ret = strrchr(str, ch);
   yert = ft_strrchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("String after |%c| is - |%s|\n", ch, yert);
   
   return(0);
}