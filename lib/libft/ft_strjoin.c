/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:06:46 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:07:15 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	t_size;

	t_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = (char *)malloc(t_size * sizeof(char));
	if (!ret)
		return ((void *) NULL);
	*ret = '\0';
	ft_strlcat(ret, s1, t_size);
	ft_strlcat(ret, s2, t_size);
	return (ret);
}
/*
#include	<stdio.h>
int	main(void)
{
	char *s1 = "0123456789";
	char *s2 = "0123456789";
	printf("s1:%s,s2:%s\n s1+s2:%s\n", s1, s2, ft_strjoin(s1, s2));
}
*/