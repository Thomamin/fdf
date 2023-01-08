/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:48:15 by dmin              #+#    #+#             */
/*   Updated: 2022/11/09 10:48:24 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ret;

	ret = (void *)malloc(count * size);
	if (!ret)
		ret = (void *) NULL;
	else
		ret = ft_memset(ret, 0, count * size);
	return ((void *) ret);
}
/*
int	main(void)
{
	char *p;

	p = ft_calloc(10, sizeof(char));
	return(0);
}
*/