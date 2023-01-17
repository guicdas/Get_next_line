#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    unsigned int i;
    int a;

    i = 0;
    a = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    while (a < nb)
    {
        dest[i+a] = src[a];
        a++;
    }
    dest[i+a] = '\0';
    return (dest);
}

int main(){
    char *dest;
    char destin[25] = "sabimo";
    char src[] = "sabindo";

    dest = ft_strncat(destin, src, 4);
    printf("%s", dest);
}