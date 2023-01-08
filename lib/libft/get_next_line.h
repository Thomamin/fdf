/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:07:13 by dmin              #+#    #+#             */
/*   Updated: 2022/11/21 19:07:53 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# else
#  if BUFFER_SIZE < 1
#   error INVALID BUFFER_SIZE
#  endif
# endif
# include <stddef.h>
# include <unistd.h>

typedef struct s_list
{
	int				fd;
	size_t			bk_size;
	void			*bk;
	struct s_list	*next;
}					t_list;

typedef struct s_line
{
	void	*line;
	size_t	sz;
}			t_line;

void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_conc_m(t_line *r_l, unsigned char *buf, size_t buf_sz);
void	*ft_c_l(t_line *r_l, unsigned char *buf, ssize_t rn, t_list *n_b);
int		ft_read_to_buff(unsigned char *buf, int fd, t_line *r_l);
void	ft_del_node(t_list **list_backup, t_list *n_b);
t_list	*ft_init_n_b(t_list **list_backup, t_list *n_b, int fd);
t_list	*ft_find_backup(t_list **list_backup, int fd);
ssize_t	ft_backup_to_buf(t_list *n_b, unsigned char *buf);
char	*get_next_line(int fd);

#endif