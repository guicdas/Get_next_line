/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcatarin <gcatarin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:11:15 by gcatarin          #+#    #+#             */
/*   Updated: 2022/12/03 23:36:08 by gcatarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define DEX "0123456789"
# define HEXAL "0123456789abcdef"
# define HEXAU "0123456789ABCDEF"

size_t	ft_strlen(char *str);

int		put_b_nbr(unsigned long long nbr, char *b, size_t bs);
int		ftp(va_list argptr);
int		ftchar(va_list argptr);
int		ftstr(va_list argptr);
int		ftint(va_list argptr, char m);

int		signal(char *c);
int		flags(char *str, va_list argptr);
int	pointcond(char *c);
int	pointaction(char *c);
int		minuscond(char *c);
int		minusaction(char *c, int ret, va_list argptr, int mfw);
int		spaceaction(int ret, int mfw);
int		spacecond(char *c);
int		percentaction(char *c, int ret, va_list argptr);
int		compare(char *str, va_list argptr);
int		tratamento(char *c, int ret, va_list argptr);
int		tratabonus(char *c, int ret, va_list argptr);
int		ft_printf(const char *c, ...);

#endif