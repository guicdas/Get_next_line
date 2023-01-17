#include <stdio.h>

char *ft_strstr(char *str, char *to_find)
{
    int i;
    int j;
    int a;

    i = 0;
    a = 0;
    while (to_find[i] != '\0')
    {
        a++;
    }
    if (a == 0)
    {
        return (str);
    }
    while (str[i] != '\0')
    {
        j = 0;
        if(str[i] != to_find[j])
        {
        }else{
            while (j < a)
            {
                j++;
                if (str[i+j] ==
            }
        }
    i++;
    }
    return(NULL);
}

int main(){
    char *dest;
    char destin[] = "mambosabsmo";
    char src[] = "bsm,";

    dest = ft_strstr(destin, src);
    printf("%s", dest);
}