/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:44:25 by dmin              #+#    #+#             */
/*   Updated: 2022/11/14 17:44:43 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	static	ft_select(const char *in_str, va_list vl)
{
	int	ret;

	ret = 0;
	if (*in_str == 'c')
		ret = ft_printf_c(vl);
	else if (*in_str == 's')
		ret = ft_printf_s(vl);
	else if (*in_str == 'p')
		ret = ft_printf_p(vl);
	else if (*in_str == 'd' || *in_str == 'i')
		ret = ft_printf_d(vl);
	else if (*in_str == 'u')
		ret = ft_printf_u(vl);
	else if (*in_str == 'x')
		ret = ft_printf_x(vl, 0);
	else if (*in_str == 'X')
		ret = ft_printf_x(vl, 1);
	else if (*in_str == '%')
		ret = ft_printf_percent();
	else
		return (-1);
	return (ret);
}

int	ft_printf(const char *in_str, ...)
{
	va_list	vl;
	int		ret;
	int		width;
	int		precs;

	ret = 0;
	width = 0;
	precs = 0;
	va_start(vl, in_str);
	while (*in_str)
	{
		if (*in_str == '%')
		{
			ret += ft_select(++in_str, vl);
		}
		else
		{
			write(1, in_str, 1);
			ret++;
		}
		in_str++;
	}
	va_end(vl);
	return (ret);
}

/*
#include <stdio.h>  //
int	main(void)
{
	char *in_str = "test";

	printf("%c, %s, %d, %u, %i, %x, %%, %p\n", \
		'a', "great", 1234, 4321, 1234567, 0x4321, in_str);
	ft_printfintf("%c, %s, %d, %u, %i, %x, %%, %p\n", \
		'a', "great", 1234, 4321, 1234567, 0x4321, in_str);

	return 0;
}
*/