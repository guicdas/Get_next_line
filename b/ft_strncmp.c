#include <stdio.h>

int ft_strncmp(const char *str1, const char *str2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n)
    {
		if (str1[i] != str2[i]){
			return (str1[i] - str2[i]);
		}
        i++;
    }
    return (0);
}

int main(){
    char s1[] = "sabimo";
    char s2[] = "sabindo";
    int a;

    a = ft_strncmp( s1, s2, 4);
    printf("%d", a);
}