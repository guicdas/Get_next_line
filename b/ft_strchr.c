
#include <stdio.h>
#include <string.h>

char *ft_strchr(const char *str, int c){
	while(*str){
		if (*str == c){
			return ((char *)str);
		}
		str++;
	}
	return (NULL);
}

int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ret;
   char * yert;

   ret = strchr(str, ch);
   yert = ft_strchr(str, ch);

   printf("String after |%c| is - |%s|\n", ch, ret);
   printf("String after |%c| is - |%s|\n", ch, yert);
   
   return(0);
}