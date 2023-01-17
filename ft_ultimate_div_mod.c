#include <stdio.h>

void ft_ultimate_div_mod(int *a, int *b);

int main()
{
    int *a, *b;
    printf("%d\n%d\nasa", &a, &b);

    ft_ultimate_div_mod(a, b);

}

void ft_ultimate_div_mod(int *a, int *b)
{
    int c, d, f, g;
    
    c = *a;
    d = *b;
    printf("%d %d %d %d", c, b, a, d);

    *a = c/d;
    *b = c%d;
    printf("%d\n%d\n%d\n%d", c, d);

}