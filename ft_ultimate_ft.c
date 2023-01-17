#include <stdio.h>

void ft_ft(int *********nbr);

int main()
{
    int a = 56;
    int *nbr1, **nbr2, ***nbr3, ****nbr4, *****nbr5, ******nbr6, *******nbr7;
    int ********nbr8, *********nbr;

    nbr1 = &a;
    nbr2 = &nbr1;
    nbr3 = &nbr2;
    nbr4 = &nbr3;
    nbr5 = &nbr4;
    nbr6 = &nbr5;
    nbr7 = &nbr6;
    nbr8 = &nbr7;

    printf("%d", a);
    ft_ft(&nbr8);
    printf("%d", a);

}

void ft_ft(int *********nbr)
{
    *********nbr = 42;
}