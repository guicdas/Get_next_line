/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:16:38 by gcatarin          #+#    #+#             */
/*   Updated: 2022/12/03 23:17:15 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	signal(char *c)
{
	--c;
	if (*c == ' ')
	{
		c++;
		return (write(1, " ", 1));
	}
	return (0);
}

int flags(char *str, va_list argptr)
{
	if (*str == '#')
	{
		str++;
		if (*str == 'x')
			return (write (1, "0x", 2) + put_b_nbr(va_arg(argptr, unsigned int), HEXAL, 16));
		if (*str == 'X')
			return (write (1, "0X", 2) + put_b_nbr(va_arg(argptr, unsigned int), HEXAU, 16));
	}
	else if (*str == '+')
	{
		str++;
		if (*str == 'd' || *str == 'i')
			return (ftint(argptr, '+'));
	}
	else if (*str == ' ')
	{
		str++;
		if (*str == 'd' || *str == 'i')
			return (signal(str) + ftint(argptr, 0));
	}
	return (0);
}

int	compare(char *str, va_list argptr)
{
	if (*str == '%')
		return (write(1, "%", 1));
	if (*str == 'd' || *str == 'i')
		return (ftint(argptr, 0));
	if (*str == 's')
		return (ftstr(argptr));
	if (*str == 'p')
		return (ftp(argptr));
	if (*str == 'c')
		return (ftchar(argptr));
	if (*str == 'u')
		return (put_b_nbr(va_arg(argptr, unsigned int), DEX, 10));
	if (*str == 'x')
		return (put_b_nbr(va_arg(argptr, unsigned int), HEXAL, 16));
	if (*str == 'X')
		return (put_b_nbr(va_arg(argptr, unsigned int), HEXAU, 16));
	return (flags(str, argptr));
}

int	tratamento(char *c, int ret, va_list argptr)
{
	while (*c)
	{
		if (*c == '%')
		{
			c++;
			ret = ret + compare(c, argptr);
		}
		else
			ret = ret + write(1, c, 1);
		c++;
	}
	return (ret);
}

int	ft_printf(const char *c, ...)
{
	int		ret;
	va_list	argptr;

	ret = 0;
	va_start(argptr, c);
	ret = tratabonus((char *)c, ret, argptr);
	va_end(argptr);
	return (ret);
}

int main(){
	int i;
	i = ft_printf(".%-d.", 12);
	printf("\n%d", i);
}