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

# ifndef X_AXIS
#  define X_AXIS 1
# endif
# ifndef Y_AXIS
#  define Y_AXIS 2
# endif
# ifndef Z_AXIS
#  define Z_AXIS 3
# endif

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
	int				cx;
	int				cy;
	int				cz;
	unsigned int	color;
}				t_c_dot;

typedef struct	s_f_dot
{
	int					fx;
	int					fy;
	unsigned int		color;
}				t_f_dot;

typedef struct	s_fdf
{
	t_c_dot	*c_dots;
	int		cnt_x;
	int		cnt_z;
}				t_fdf;

typedef struct	s_imgsz
{
	int	min_x;
	int	min_y;
	int	max_x;
	int	max_y;
}				t_imgsz;

t_f_dot to_f(t_c_dot dot, double radian, t_imgsz size);
void	ft_drawline(t_data *data, t_f_dot f0, t_f_dot f1, unsigned int color);
void	my_mlx_pixel_put(t_data *data, t_f_dot f);
void 	my_hook(void *win, void *param);
void	my_loop_hook(void *mlx, void *args);
int		render_next_frame(void *mlx, t_fdf *fdata);
void	*ft_read_fdf(t_fdf *fdf, int fd);
int		to_fx(t_c_dot dot, double radian, t_imgsz *size);
int		to_fy(t_c_dot dot, double radian, t_imgsz *size);
void	ft_c_rotate(t_fdf *fdf, int axit, int degree_theta);
void	ft_c_zoom(t_fdf *fdf, float times);
void	ft_drawmesh(t_fdf *fdf, t_data *img, double rad, unsigned int color, t_imgsz size);
t_args	*my_init_mlx_win(t_args *mlx_arg, t_data *img, t_imgsz size);
void	*ft_err_mng(int err_code, char *err_msg, void *mem1, void *mem2);

#endif