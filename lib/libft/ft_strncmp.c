/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:49:08 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 16:49:10 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				ret;

	ret = 0;
	if (n != 0)
	{
		p1 = (unsigned char *) s1;
		p2 = (unsigned char *) s2;
		ret = *p1 - *p2;
		p1++;
		p2++;
		while (*(p1 - 1) && *(p2 - 1) && ret == 0 && --n)
		{
			ret = *p1 - *p2;
			p1++;
			p2++;
		}
	}
	return (ret);
}
/*
#include <stdio.h> 
#include <string.h>

int	main(void)
{
	char *s1 = "abcdef";
	char *s2 = "abcd  11";
	printf("s1(%lu) = %s vs. s2(%lu) = %s  | result %d\n", strlen(s1), s1, \
	strlen(s2), s2, strncmp (s1, s2, 4));
	printf("s1(%lu) = %s vs. s2(%lu) = %s  | result %d\n", strlen(s1), s1, \
	strlen(s2), s2, ft_strncmp (s1, s2, 4));
	return(0) ;

}
*/