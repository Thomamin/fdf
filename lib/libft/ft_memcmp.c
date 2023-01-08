/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:19:30 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 17:19:52 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				ret;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	ret = 0;
	while (ret == 0 && n--)
	{
		ret = *p1 - *p2;
		p1++;
		p2++;
	}
	return (ret);
}
/*
#include <stdio.h> 
#include <string.h>

int	main(void)
{
	char *s1 = "1234";
	char *s2 = "123 ";
	char *s3 = "1234";
	char *s4 = "123 ";
	printf("s1(%lu) = %s vs. s2(%lu) = %s  | result %d\n", strlen(s1), s1, \
	strlen(s2), s2, memcmp (s1, s2, 1));
	printf("s1(%lu) = %s vs. s2(%lu) = %s  | result %d\n", strlen(s1), s1, \
	strlen(s2), s2, ft_memcmp (s1, s2, 1));
	return(0) ;
}
*/