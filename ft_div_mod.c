#include <stdio.h>

void ft_ft(int a, int b, int *div, int *mod);

int main()
{
    int a=10, b=4;
    int *div, *mod;

    ft_ft(a, b, div, mod);

}

void ft_ft(int a, int b, int *div, int *mod)
{
    int f,g;
    
    f=a/b; 
    g=a%b;

    div=&f;
    mod=&g;

}