/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:38:46 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 12:39:54 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = b;
	while (len--)
	{
		*str++ = (unsigned char) c;
	}
	return (b);
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