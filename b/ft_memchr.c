#include <stdio.h>
#include <string.h>

void *ft_memchr(const void *str, int c, size_t n){
	unsigned char *s;
	size_t i;

	s = (unsigned char *) str;
	i = 0;
	while(*s && i < n){
		if (*s == c){
			return ((char *)s);
		}
		s++;
		i++;
	}
	return (NULL);
}


int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = '.';
   char *ter;
   char *ret;


   ret = ft_memchr(str, ch, 4);
   ter = memchr(str, ch, 4);

   printf("String after |%c| is - |%s|\n", ch, ter);
   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}