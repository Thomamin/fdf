/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:35:48 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:40:08 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "libft.h"

int	ft_isalnum(int c)
{
	int	result;

	if (ft_isalpha(c) || ft_isdigit(c))
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

	c = ';';
	printf("%d\n", ft_isalnum(c)); 
	return (0);
}
*/