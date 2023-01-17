#include <unistd.h>
#include <stdio.h>

char int_to_hex(int num)
{
    char digit;
    if (num < 10)
    {
        digit = num + 48;
    }
    else
    {
        if (num == 10)
            digit = 'a';
        if (num == 11)
            digit = 'b';
        if (num == 12)
            digit = 'c';
        if (num ==13)
            digit = 'd';
        if (num == 14)
            digit = 'e';
        if (num == 15)
            digit = 'f';
    }

    return (digit);
}

char    convert_to_char_res(int str)
{
    char res;

    res = int_to_hex(str / 16);
    return (res);
}
char    convert_to_char_rem(int str)
{
    char rem;

    rem = int_to_hex(str % 16);
    return (rem);
}

void ft_putstr_non_printable(char *str)
{
    int i;
    char c;

    i = 0;
    while (str[i] != '\0')
    {
        if(str[i] < 32 && str[i] < 126)
        {
            c = 92;
            write(1, &c, 1);
            c = convert_to_char_res(str[i]);
            write(1, &c, 1);
            c = convert_to_char_rem(str[i]);
            write(1, &c, 1);
            i++;
        }else
        {
            write(1, &str[i], 1);
        i++;
        }
    }
}

int main(){
    char *src;
    src = "Coucou\ntu\b \fvas bien ?";

    ft_putstr_non_printable(src);

}