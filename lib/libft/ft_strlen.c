/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:51:12 by dmin              #+#    #+#             */
/*   Updated: 2022/10/03 10:55:02 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*tmp_str;

	tmp_str = str;
	while (*str != '\0')
	{
		str++;
	}
	return (str - tmp_str);
}
/*
int	main(void)
{
	size_t len;

	len = ft_strlen("Just do it!");

	return (0);
}
*/
