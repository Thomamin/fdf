/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:41:09 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 13:41:12 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = dst;
	s = src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	int c;
	char carr[10];
	
	c = 'a';
	printf("%s\n", ft_memset(&carr[0], c, 9));
}
*/
