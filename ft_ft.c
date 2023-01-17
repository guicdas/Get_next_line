void ft_ft(int *nbr);

int main()
{
    int a = 56;
    int *nbr;

    printf("%d", a);
    ft_ft(&a);
    printf("%d", a);

}

void ft_ft(int *nbr)
{
    *nbr = 42;
}