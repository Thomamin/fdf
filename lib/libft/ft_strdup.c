/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:18:45 by dmin              #+#    #+#             */
/*   Updated: 2022/11/09 11:18:47 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p_str;
	char	*tmp;

	p_str = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p_str)
		return ((char *) NULL);
	tmp = p_str;
	while (*s1 && p_str != 0)
	{
		*p_str = *s1;
		s1++;
		p_str++;
	}
	*p_str = '\0';
	return (tmp);
}
/*
#include	<stdio.h>
#include	<string.h>
int	main(void)
{
	char *tmp;
	char *str = "marriage is heaven and hell at the sametime";
	tmp = strdup(str);
	printf("src : %s\nstrdup : %s\n", str, tmp);
	free(tmp);
}
*/