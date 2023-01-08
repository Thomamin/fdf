/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:30:27 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 17:30:29 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char						*p_ret;
	int							found;
	unsigned long				len_needle;

	found = 0;
	p_ret = (char *) NULL;
	if (*needle)
	{
		len_needle = ft_strlen(needle);
		while (*haystack && *needle && !found && len-- >= len_needle)
		{
			if (*haystack == *needle)
				found = !(ft_strncmp(haystack, needle, len_needle));
			if (found)
				p_ret = (char *) haystack;
			else
				haystack++;
		}
	}
	else
		p_ret = (char *) haystack;
	return (p_ret);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
//	char  *haystack = "012345";
//	char	*needle = "34";
	char  *haystack = "012";
	char	*needle = "12";

	printf("Haystack:%s Needle:%s RESULT:%s\n", \
					haystack, needle, strnstr(haystack, needle, 3));

	printf("Haystack:%s Needle:%s RESULT:%s\n", \
					haystack, needle, ft_strnstr(haystack, needle, 3));

	return (0);
}
*/