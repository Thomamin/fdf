/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:31:10 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:32:19 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	int	result;

	if (c >= '0' && c <= '9')
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
	printf("%d\n", ft_isdigit(c)); 
	return (0);
}
*/