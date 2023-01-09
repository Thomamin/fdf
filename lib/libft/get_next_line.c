/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:05:13 by dmin              #+#    #+#             */
/*   Updated: 2022/11/21 19:07:00 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	ft_del_node(t_gnl_list **list_backup, t_gnl_list *n_b)
{
	t_gnl_list	*node;

	node = *list_backup;
	if (node == n_b)
	{
		*list_backup = n_b->next;
		if (n_b->bk != NULL)
			free(n_b->bk);
		free(n_b);
	}
	else
	{
		while (node != NULL)
		{
			if (node->next == n_b)
			{
				node->next = n_b->next;
				if (n_b->bk != NULL)
					free(n_b->bk);
				free(n_b);
			}
			node = node->next;
		}
	}
}

t_gnl_list	*ft_init_n_b(t_gnl_list **list_backup, t_gnl_list *n_b, int fd)
{
	n_b->fd = fd;
	n_b->bk = NULL;
	n_b->next = NULL;
	n_b->bk_size = 0;
	if (*list_backup)
		n_b->next = *list_backup;
	*list_backup = n_b;
	return (n_b);
}

t_gnl_list	*ft_find_backup(t_gnl_list **list_backup, int fd)
{	
	t_gnl_list	*n_b;

	if (fd < 0)
		return ((t_gnl_list *) NULL);
	if (list_backup != NULL)
	{
		n_b = *list_backup;
		while (n_b != NULL)
		{
			if (n_b->fd == fd)
				return (n_b);
			else
				n_b = n_b->next;
		}
	}
	n_b = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!n_b)
		return ((t_gnl_list *) NULL);
	return (ft_init_n_b(list_backup, n_b, fd));
}

ssize_t	ft_backup_to_buf(t_gnl_list *n_b, unsigned char *buf)
{
	int	n;

	if (n_b->bk != NULL)
	{
		n = BUFFER_SIZE;
		while (n--)
			*buf++ = '\0';
		buf = buf - BUFFER_SIZE;
		ft_memcpy(buf, n_b->bk, n_b->bk_size);
	}
	return (n_b->bk_size);
}

char	*get_next_line(int fd)
{
	ssize_t					rn;
	unsigned char			buf[BUFFER_SIZE + 1];
	static t_gnl_list			*l_b;
	t_gnl_list					*n_b;
	t_line					r_l;

	r_l.line = NULL;
	r_l.sz = 0;
	buf[BUFFER_SIZE] = '\0';
	n_b = ft_find_backup(&l_b, fd);
	if (n_b == NULL)
		return ((char *) NULL);
	rn = ft_backup_to_buf(n_b, buf);
	if (rn <= 0)
		rn = ft_read_to_buff(buf, fd, &r_l);
	while (rn > 0)
	{
		if (ft_memchr(buf, '\n', rn))
			return ((char *)ft_c_l(&r_l, buf, rn, n_b));
		r_l.line = ft_conc_m(&r_l, buf, rn);
		rn = ft_read_to_buff(buf, fd, &r_l);
	}
	ft_del_node(&l_b, n_b);
	return ((char *)r_l.line);
}
