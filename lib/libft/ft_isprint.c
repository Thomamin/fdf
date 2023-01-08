/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:06:37 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 12:06:55 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	int	result;

	if (c >= ' ' && c <= '~')
			result = 1;
	else
			result = 0;
	return (result);
}
/*
#include <stdio.h>
int main(void)
{
	unsigned char c;

	c = '0';
	printf("%d\n", ft_isprint(c)); 
	return (0);
}
*/