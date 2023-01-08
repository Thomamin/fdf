/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:22:13 by dmin              #+#    #+#             */
/*   Updated: 2022/11/09 10:22:16 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_str_to_l(const char *str, long num)
{
	long	res;

	res = 0;
	if (*str >= '0' && *str <= '9')
		res = ft_str_to_l(str + 1, (num * 10 + (*str - '0')));
	else
		res = num;
	return (res);
}

int	ft_atoi(const char *str)
{
	int		sgn;
	long	l_number;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' \
			|| *str == '\r' || *str == '\f')
		str++;
	sgn = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sgn = -1;
		str++;
	}
	l_number = ft_str_to_l(str, 0);
	l_number = l_number * sgn;
	return ((int)l_number);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "9876543210";

	printf("%d\n", (int)strtol(str, (char **)NULL, 10));
	printf("%d\n", ft_atoi(str));
}
*/