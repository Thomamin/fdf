/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:15:12 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 16:15:18 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "    abcd";
	printf("%s\n", ft_strchr(str, 'a'));
}
*/