/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:14:42 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:22:21 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	result;

	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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
	printf("%d\n", ft_isalpha(c)); 
	return (0);
}
*/