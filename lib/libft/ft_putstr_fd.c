/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:11:49 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:11:56 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
}

/*
#include	<stdio.h>
#include	<fcntl.h>
int	main(void)
{
	int	fd = open("test.txt", O_WRONLY);
	ft_putstr_fd("this is the real life is this fantasy?", fd);
	close(fd);
}
*/
