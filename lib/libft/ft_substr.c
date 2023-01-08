/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:05:29 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:06:26 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	t_len;
	char	*ret;

	s_len = ft_strlen(s);
	if (start <= s_len)
	{
		if (len > s_len - start)
			t_len = s_len - start;
		else
			t_len = len;
	}
	else
		t_len = 0;
	ret = (char *) malloc((t_len + 1) * sizeof(char));
	if (!ret)
		return ((char *) NULL);
	ret = (char *) ft_memcpy(ret, (const void *)(s + start), \
											t_len * sizeof(char));
	*(ret + t_len) = '\0';
	return (ret);
}
/*
#include <stdio.h>
int	main(void)
{
	char *src = "012345678901234567890123456789";

	printf("src: %s\nsub: %s\n", src, ft_substr(src, 5, 20));
}
*/