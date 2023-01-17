#include <stdio.h>

int ft_sqrt(int nb)
{
    if (index <= 0)
    {
        return (0);
    }
    if (index == 1 || index == 2)
    {
        return (1);
    }
    else
    {
        nb = fibonacci(index - 2) + fibonacci(index - 1);
    }
    return (nb);
}

int main(){
int nb=9;
int n;

n = ft_sqrt(nb);
printf("%d", n);
}