#include <stdio.h>
#include <string.h>

char *ft_strnstr(const char	*big, const char *little, size_t len)
{
	int i;
	size_t a;

	i = 0;
	a = 0;
	if (*little == '/0'){
		return ((char *)big);
	}
	while(*little){
		little++;
		i++;
	}
	while(*big && a < len){
		while(*big == *little)
			return ((char *)big);
		}
		big++;
		a++;
	}
	return (NULL);
}

void main () {
   char str1[15];
   char str2[15];
   int ret;
   int ref;

   memcpy(str1, "abcdef", 6);
   memcpy(str2, "ABCDEF", 6);

   ret = strnstr(str1, str2, 5);
   ref = ft_strnstr(str1, str2, 5);

	printf("%s %s", ret, ref);
}