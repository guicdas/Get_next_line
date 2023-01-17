#include <stdio.h>

int      ft_strcmp(char *s1, char *s2)
{
    int i;
    int a;

    i = 0;
    a = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] > s2[i])
        {
            a++;
            return (a);
        }else if (s1[i] < s2[i])
        {
            a--;
            return (a);
        }
        i++;
    }
    return (a);
}

int main(){
    char s1[] = "cb";
    char s2[] = "ca";
    int a;

    a = ft_strcmp( s1, s2);
    printf("%d", a);
}