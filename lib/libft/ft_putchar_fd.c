/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:11:07 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:11:24 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(char));
}

/*
#include	<stdio.h>
#include	<fcntl.h>
int	main(void)
{
	int	fd = open("test.txt", O_WRONLY);
	ft_putchar_fd('N', fd);
	close(fd);
}
*/