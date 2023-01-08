/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:11:38 by dmin              #+#    #+#             */
/*   Updated: 2022/11/08 17:12:03 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsz)
{
	unsigned int	original_dest_size;
	unsigned int	original_src_size;
	unsigned int	inc;

	original_dest_size = ft_strlen(dst);
	original_src_size = ft_strlen(src);
	if (original_dest_size < dstsz)
	{
		while (*dst)
		{
			dst++;
		}
		inc = 1;
		while (*src && inc < dstsz - original_dest_size)
		{
			*dst = *src;
			src++;
			dst++;
			inc++;
		}
		*dst = '\0';
		return (original_dest_size + original_src_size);
	}
	else
		return (original_src_size + dstsz);
}
/*
#include <stdio.h> 
#include <string.h>

int	main(void)
{


	char	f_dest[21] = "0123456789";   // 10 characters
	char	f_dest1[21] = "9876543210";
	char	f_src[21] = "12345678901234567890";	// 20 characters
	
	printf("strlcat\t\t:  %lu\nft_strlcat\t:  %lu\n", \
			strlcat(f_dest, f_src, 21), ft_strlcat(f_dest1, f_src, 21));
	printf("strlcat\t\t: %s\nft_strlcat\t: %s\n", f_dest, f_dest1);

	char	f_dest2[16] = "swimming ";
	char	f_dest3[16] = "swimming ";
	
	printf("strlcat\t\t:  %lu\nft_strlcat\t:  %lu\n",
			strlcat(f_dest2, f_src, 16), ft_strlcat(f_dest3, f_src, 16));
	printf("strlcat\t\t: %s\nft_strlcat\t: %s\n", f_dest2, f_dest3);

	return (0);
}
*/