/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:35:32 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 16:35:34 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	cc;

	len = ft_strlen(s) + 1;
	cc = (char) c;
	while (len--)
	{
		if (*(s + len) == cc)
			return ((char *)(s + len));
	}
	return (0);
}
/*
#include <stdio.h>
int	main(void)
{
	char *str = "acd    ";
	printf("%s\n", ft_strrchr(str, '\0'));
}
*/