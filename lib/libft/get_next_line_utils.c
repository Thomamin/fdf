/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:06:13 by dmin              #+#    #+#             */
/*   Updated: 2023/01/03 13:25:15 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cp;
	unsigned char	uc;

	cp = (unsigned char *) s;
	uc = (unsigned char) c;
	while (n--)
	{
		if (*cp == uc)
			return ((void *) cp);
		cp++;
	}
	return ((void *) NULL);
}

void	*ft_conc_m(t_line *r_l, unsigned char *buf, size_t buf_sz)
{
	unsigned char	*new_mem;

	if (r_l->sz + buf_sz == 0)
		return ((void *) NULL);
	new_mem = (unsigned char *)malloc(r_l->sz + buf_sz + 1);
	if (!new_mem)
	{
		free(r_l->line);
		r_l->sz = 0;
		return ((void *) NULL);
	}
	new_mem = (unsigned char *)ft_memcpy(new_mem, r_l->line, r_l->sz);
	ft_memcpy(new_mem + r_l->sz, buf, buf_sz);
	free(r_l->line);
	r_l->sz += buf_sz;
	*(new_mem + r_l->sz) = '\0';
	return (new_mem);
}

void	*ft_c_l(t_line *r_l, unsigned char *buf, ssize_t rn, t_list *n_b)
{
	unsigned char	*new_mem;
	unsigned char	*r_mem;
	unsigned char	*nl_p;

	nl_p = (unsigned char *)ft_memchr(buf, '\n', rn);
	nl_p++;
	new_mem = (unsigned char *)ft_conc_m(r_l, buf, nl_p - buf);
	if (!new_mem)
		return ((void *) NULL);
	r_mem = (unsigned char *)malloc(rn - (nl_p - buf) + 1);
	if (!r_mem)
	{
		free(new_mem);
		return ((void *) NULL);
	}	
	r_mem = (unsigned char *)ft_memcpy(r_mem, nl_p, rn - (nl_p - buf));
	*(r_mem + rn - (nl_p - buf)) = '\0';
	if (n_b->bk != NULL)
		free(n_b->bk);
	n_b->bk = r_mem;
	n_b->bk_size = rn - (nl_p - buf);
	return (new_mem);
}

int	ft_read_to_buff(unsigned char *buf, int fd, t_line *r_l)
{
	int	n;
	int	res;

	n = BUFFER_SIZE;
	while (n--)
		*buf++ = 0;
	buf = buf - BUFFER_SIZE;
	res = read(fd, buf, BUFFER_SIZE);
	if (res < 0 && r_l->line != NULL)
	{
		free(r_l->line);
		r_l->line = NULL;
		r_l->sz = 0;
	}
	return (res);
}
