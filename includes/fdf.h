/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:28:55 by dmin              #+#    #+#             */
/*   Updated: 2023/01/04 12:28:58 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_args {
	void	*mlx;
	void	*win;
}				t_args;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_c_dot
{
	int		cx;
	int		cy;
	int		cz;
	int		color;
}				t_c_dot;

typedef struct	s_f_dot
{
	int		fx;
	int		fy;
	int		color;
}				t_f_dot;

typedef struct	s_fdf
{
	t_c_dot	**c_dots;
}				t_fdf;


t_f_dot to_f(t_data *data, t_c_dot dot, double radian);
void	ft_drawline(t_data *data, t_f_dot f1, t_f_dot f2, int color);
void	my_mlx_pixel_put(t_data *data, t_f_dot f);
void 	my_hook(void *win, void *param);
void	my_loop_hook(void *mlx, void *args);
int		render_next_frame(void *mlx, t_fdf *fdata);
t_c_dot	*ft_read_fdf(int fd, void *mlx, void *mlx_win, t_data *img);

#endif