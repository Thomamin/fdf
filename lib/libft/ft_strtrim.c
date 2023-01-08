/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:07:51 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:08:03 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	t_len;
	size_t	start;
	size_t	end;

	t_len = ft_strlen(s1);
	start = 0;
	while (start < t_len && (ft_strchr(set, *(s1 + start))))
		start++;

	end = t_len - 1;
	while (end > 0 && (ft_strchr(set, *(s1 + end))))
		end--;
	
	if (end >= start)
		ret = ft_substr(s1, start, end - start + 1);
	else
		ret = ft_substr(s1, 0, 0);
	if (!ret)
		return ((char *) NULL);
	return (ret);
}
/*
#include	<stdio.h>
int	main(void)
{
	char	*s1 = "        ";
	char	*set = " ";

	printf("%s", ft_strtrim(s1, set));
}
*/