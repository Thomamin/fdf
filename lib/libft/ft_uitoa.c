/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:09:09 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:09:21 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_alloc_size(long ll_num, int base)
{
	int	i;

	if (ll_num == 0)
		return (2);
	i = 0;
	if (ll_num < 0)
	{
		i++;
		ll_num *= -1;
	}
	while (ll_num > 0)
	{
		i++;
		ll_num /= base;
	}
	return (i + 1);
}

static char	*ft_itoa_r(long n, char *ret)
{
	long		next_in;
	long		in;

	in = n;
	if (in == 0)
	{
		*ret = '0';
		ret++;
	}
	else
	{
		if (in < 0)
		{
			*ret = '-';
			ret++;
			in = -1 * in;
		}
		next_in = in / 10;
		if (next_in > 0)
			ret = ft_itoa_r(next_in, ret);
		*ret = '0' + (in % 10);
		ret++;
	}
	return (ret);
}

char	*ft_uitoa(int in_n, int is_unsigned)
{
	int		len;
	char	*ret;
	long	n;

	if (is_unsigned)
		n = (unsigned int)in_n;
	else
		n = (int)in_n;
	len = ft_alloc_size(n, 10);
	ret = (char *)malloc(len * sizeof(char));
	if (!ret)
		return ((char *) NULL);
	ret = ft_itoa_r(n, ret);
	*ret = '\0';
	return (ret + 1 - len);
}
