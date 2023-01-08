/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:05:21 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 13:05:27 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = s;
	while (n--)
	{
		*p++ = 0;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	int n;
	char carr[10];
	char carr2[10];
	
	n = 3;
	printf("%s\n", bzero(&carr[0], n));
	printf("%s\n", ft_bzero(&carr2[0], n));
}
*/