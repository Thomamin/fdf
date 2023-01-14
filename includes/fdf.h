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

#  define X_AXIS 1
#  define Y_AXIS 2
#  define Z_AXIS 3
#  define ISO    0
#  define ONEP   1	

typedef struct	s_args {
	void	*mlx;
	void	*win;
}				t_args;

typedef struct	s_c_dot
{
	double			cx;
	double			cy;
	double			cz;
	unsigned int	color;
}				t_c_dot;

typedef struct	s_f_dot
{
	int				fx;
	int				fy;
	unsigned int	color;
}				t_f_dot;

typedef struct	s_fdf
{
	t_c_dot	*c_dots;
	int		cnt_x;
	int		cnt_z;
}				t_fdf;

typedef struct	s_imgsz
{
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	double	mid_cx;
	double	mid_cy;
	double	mid_cz;
	double	mn_cx;
	double	mn_cy;
	double	mn_cz;
	double	mx_cx;
	double	mx_cy;
	double	mx_cz;
}				t_imgsz;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_imgsz	size;
	float	times;
	int		x_rot;
	int		y_rot;
	double	x_mv;
	double	y_mv;
	double	z_mv;
	int		draw_axis;
	int		view_mode;
	void	*mlx;
	void	*win;
	double	radian;
	t_fdf	*fdf;
}				t_data;

t_f_dot to_f(t_c_dot dot, double radian, t_imgsz *size, int mode);
void	ft_dline(t_data *data, t_f_dot f0, t_f_dot f1, unsigned int color);
void	my_mlx_pixel_put(t_data *data, t_f_dot f);
void 	my_hook(t_data *img);
void	my_loop_hook(t_data *img, t_fdf *fdf);
int		render_next_frame(t_data *img);
t_c_dot	*ft_read_fdf(t_fdf *fdf, int fd);
void	ft_c_rotate(t_fdf *fdf, int axit, int degree_theta);
void	ft_c_zoom(t_fdf *fdf, float times);
void	ft_c_move(t_fdf *fdf, double xm, double ym, double zm);
void	ft_drawmesh(t_fdf *fdf, t_data *img, unsigned int color);
t_data	*my_init_mlx_win(t_data *img);
void	*ft_err_mng(int err_code, char *err_msg, void *mem1, void *mem2);
void	ft_draw_axis(t_data *img, double rad, t_imgsz size);

#endif