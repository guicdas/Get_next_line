#include <stdio.h>

char *ft_strcat(char *dest, char *src)
{
    int i;
    int a;

    i = 0;
    a = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (src[a] != '\0')
    {
        dest[i] = src[a];
        i++;
        a++;
    }
    dest[i] = '\0';
    return (dest);
}

int main(){
    char *dest;
    char destin[25] = "sabimo";
    char src[] = "sabindo";

    dest = ft_strcat(destin, src);
    printf("%s", dest);
}