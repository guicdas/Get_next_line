#include <stdio.h>

int fibonacci(int index)
{
    int nb;

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
int index=10;
int n;

n = fibonacci(index);
printf("%d", n);
}