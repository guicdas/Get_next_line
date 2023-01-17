#include <stdio.h>

void ft_ft(int *a, int *b);

int main()
{
    int n1 = 56, n2=35;
    int *a, *b;

    printf("%d%d\n\n", n2, n1);
    ft_ft(&n1, &n2);
    printf("\n\n%d%d", n2, n1);

}

void ft_ft(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}