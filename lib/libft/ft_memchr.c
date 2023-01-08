/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:11:35 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 17:11:42 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cp;
	unsigned char	uc;

	cp = (unsigned char *) s;
	uc = (unsigned char) c;
	while (n--)
	{
		if (*cp == uc)
			return ((void *) cp);
		cp++;
	}
	return (0);
}
