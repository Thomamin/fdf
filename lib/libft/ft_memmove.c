/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:23:59 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 14:24:02 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (src > dst)
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		while (len--)
		{
			*(d + len) = *(s + len);
		}
	}
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	char carr[10] = "abcdefg";
	//char carr2[10] = "1234567";
	//printf("%s\n", ft_memcpy(&carr[0], &carr[2], 3));
	printf("%s\n", ft_memmove(&carr[0], &carr[2], 3));
}
*/