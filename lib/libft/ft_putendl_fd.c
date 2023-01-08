/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:12:28 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:12:38 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
/*
#include	<stdio.h>
#include	<fcntl.h>
int	main(void)
{
	int	fd = open("test.txt", O_WRONLY);
	ft_putendl_fd("this is the real life is this fantasy?", fd);
	close(fd);
}
*/