/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:22:26 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 15:22:32 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsz)
{
	size_t			src_size;
	unsigned int	inc;

	src_size = ft_strlen(src);
	if (0 < dstsz)
	{
		inc = 0;
		while (*src && inc < dstsz - 1)
		{
			*dst = *src;
			src++;
			dst++;
			inc++;
		}
		*dst = '\0';
	}
	return (src_size);
}
/*
#include <stdio.h> 
#include <string.h>

int	main(void)
{


	char	f_dest[20] = "swimming";   // 8 characters
	char	f_dest1[20] = "swimming";
	char	f_src[21] = "12345678901234567890";	// 20 characters
	
	printf("strlcpy\t\t:  %lu\nft_strlcpy\t:  %u\n", \
			strlcpy(f_dest, f_src, 8), ft_strlcpy(f_dest1, f_src, 8));
	printf("strlcpy\t\t: %s\nft_strlcpy\t: %s\n", f_dest, f_dest1);

	char	f_dest2[16] = "swimming ";
	char	f_dest3[16] = "swimming ";
	
	printf("strlcpy\t\t:  %lu\nft_strlcpy\t:  %u\n",
			strlcpy(f_dest2, f_src, 16), ft_strlcpy(f_dest3, f_src, 16));
	printf("strlcpy\t\t: %s\nft_strlcpy\t: %s\n", f_dest2, f_dest3);

	return (0);
}
*/