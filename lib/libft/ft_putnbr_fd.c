/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:13:19 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:13:28 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long		next_in;
	long		in;

	in = n;
	if (in == 0)
	{
		ft_putchar_fd('0', fd);
	}
	else
	{
		if (in < 0)
		{
			ft_putchar_fd('-', fd);
			in = -1 * in;
		}
		next_in = in / 10;
		if (next_in > 0)
			ft_putnbr_fd(next_in, fd);
		ft_putchar_fd('0' + (in % 10), fd);
	}
}
/*
#include	<stdio.h>
#include	<fcntl.h>
int	main(void)
{
	int	fd = open("test.txt", O_WRONLY);
	ft_putnbr_fd(-7654321, fd);
	close(fd);
}
*/