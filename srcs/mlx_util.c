#include <mlx.h>
#include "fdf.h"

void	ft_draw_x_lines(t_fdf *fdf, t_data *img)
{
	int		i;
	int		j;
	t_c_dot	*c_dots;
	double	rad;

	i = 0;
	rad = img->radian;
	c_dots = fdf->c_dots;
	while (i < fdf->cnt_z)
	{
		j = 0;
		while (j < fdf->cnt_x - 1)
		{
			ft_dline(img, \
				to_f(c_dots[i * (fdf->cnt_x) + j], rad, &img->size, \
				img->view_mode), to_f(c_dots[i * (fdf->cnt_x) + j + 1], \
				rad, &img->size, img->view_mode));
			j++;
		}
		i++;
	}	
}

void	ft_draw_z_lines(t_fdf *fdf, t_data *img)
{
	int		i;
	int		j;
	t_c_dot	*c_dots;
	double	rad;

	i = 0;
	rad = img->radian;
	c_dots = fdf->c_dots;
	while (i < fdf->cnt_x)
	{
		j = 0;
		while (j < fdf->cnt_z - 1)
		{
			ft_dline(img, to_f(c_dots[j * (fdf->cnt_x) + i], rad, &img->size, \
				img->view_mode), to_f(c_dots[(j + 1) * (fdf->cnt_x) + i], rad, \
				&img->size, img->view_mode));
			j++;
		}
		i++;
	}
}

void	ft_drawmesh(t_fdf *fdf, t_data *img)
{
	ft_draw_x_lines(fdf, img);
	ft_draw_z_lines(fdf, img);
}

t_data	*my_init_mlx_win(t_data *img)
{
	int	width;
	int	height;

	width = img->size.max_x - img->size.min_x + 100;
	height = img->size.max_y - img->size.min_y + 100;
	if (width > 4000)
		width = 4000;
	if (height > 2000)
		height = 2000;
	img->mlx = mlx_init();
	if (!img->mlx)
		return (ft_err_mng(20, "Can't connect graphical system", 0, 0));
	img->win = mlx_new_window(img->mlx, width, height, "dmin's FDF");
	img->img = mlx_new_image(img->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
							&img->line_length, &img->endian);
	return (img);
}

void	ft_draw_axis(t_data *img, double rad, t_imgsz size)
{
	t_c_dot	s_dot;
	t_c_dot	e_dot;

	s_dot.cx = -5000;
	s_dot.cy = img->size.mid_cy;
	s_dot.cz = img->size.mid_cz;
	e_dot = s_dot;
	e_dot.cx = 5000;
	ft_dline(img, to_f(s_dot, rad, &size, img->view_mode), \
		to_f(e_dot, rad, &size, img->view_mode));
	s_dot.cx = img->size.mid_cx;
	s_dot.cy = -5000;
	s_dot.cz = img->size.mid_cz;
	e_dot = s_dot;
	e_dot.cy = 5000;
	ft_dline(img, to_f(s_dot, rad, &size, img->view_mode), \
		to_f(e_dot, rad, &size, img->view_mode));
	s_dot.cx = img->size.mid_cx;
	s_dot.cy = img->size.mid_cy;
	s_dot.cz = -5000;
	e_dot = s_dot;
	e_dot.cz = 5000;
	ft_dline(img, to_f(s_dot, rad, &size, img->view_mode), \
		to_f(e_dot, rad, &size, img->view_mode));
}
