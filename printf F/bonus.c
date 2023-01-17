/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:16:52 by gcatarin          #+#    #+#             */
/*   Updated: 2022/12/03 23:39:05 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	spaceaction( int ret, int mfw)
{
	while (mfw--)
		ret = ret + write(1, "0", 1);
	return (ret);
}

int	minuscond(char *c)
{
	if (*c == '-')
		return (1);
	return (0);
}

int	minusaction(char *c, int ret, va_list argptr, int mfw)
{
	if (mfw > 0)
	{
		c++;
		ret = ret + compare(c, argptr);
		ret = ret + spaceaction( ret, mfw);
		c++;
	}
	else
	{
		ret = ret + compare(c, argptr);
	}
	return (ret);
}

int	pointaction(char *c)
{
	int	mfw;

	mfw = 0;
	if (*c == '.')
	{
		c++;
		while (*c >= '0' && *c <= '9')
		{
			mfw = (mfw * 10) + *c;
			c++;
		}
	}
	return (mfw);
}

int	pointcond(char *c)
{
	if (*c == '.')
		return (1);
	return (0);
}

int	percentaction(char *c, int ret, va_list argptr)
{
	int	mfw;

	mfw = 0;
	c++;
	if (minuscond(c))
	{
		c++;
		if (pointcond(c))
			mfw = pointaction(c);
		ret = ret + minusaction(c, ret, argptr, mfw);
	}
	else
	{
		if (pointcond(c))
		{
			mfw = pointaction(c);
			c++;
			ret = ret + spaceaction( ret, mfw);
		}
		else
		{
			ret = ret + compare(c, argptr);
			c++;
		}
	}
	return (ret);
}


int	tratabonus(char *c, int ret, va_list argptr)
{
	while (*c)
	{
		if (*c == '%')
		{
			c++;
			ret = ret + percentaction(c, ret, argptr);
		}
		else
			ret = ret + write(1, c, 1);
		c++;
	}
	return (ret);
}
