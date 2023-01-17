#include <stdio.h>
#include <unistd.h>

int  divide(int nb, int div)
{
    int result;
    
    result = nb % div;
    return (result);
}

char int_to_char(int nb, int div)
{
    char character;
    int res;

    while (div != 1)
    {
        res = nb % div;
        div = div / 10;
    }

    return (character);
}

int    ft_putstr(int nb)
{
    int i;
    int result;
    int div;

    i = 0;
    div = 1;
    if (divide(nb, div) != nb)
    {
        div = div * 10;
        i++;           
    }else{
        result = divide(nb, div);
        write(1, result, i);
    }
    return (result);
}

int main(){
int nb=42;

ft_putstr(nb);
}