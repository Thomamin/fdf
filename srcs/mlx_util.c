#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, t_f_dot f)
{
	char	*dst;

	dst = NULL;
	if (f.fx > 0 && f.fx < img->size.max_x - img->size.min_x + 100 && f.fy < img->size.max_y - img->size.min_y + 100 && f.fy > 0)
	{
		dst = img->addr + (f.fy * img->line_length + f.fx * (img->bits_per_pixel / 8));
		*(unsigned int*)dst = f.color;
	}
}

void	ft_drawline_h(t_data *data, t_f_dot f0, t_f_dot f1, unsigned int color)
{
    t_f_dot df;
	int		p;
	t_f_dot	f;
	int		inc;
 
 	df.fx = f1.fx - f0.fx;
	df.fy = f1.fy - f0.fy;
	inc = 1;
	if (df.fx < 0)
	{
		inc = -1;
		df.fx = df.fx * -1;
	}
	f = f0;
	p = 2 * df.fx - df.fy;
	f.color = color;
	while(f.fy < f1.fy)
	{
		my_mlx_pixel_put(data, f);
		if(p >= 0)
		{
			f.fx = f.fx + inc;
			p = p + 2 * (df.fx - df.fy);
		}
		else
			p = p + 2 * df.fx;
		f.fy++;
	}
}

void	ft_drawline_w(t_data *data, t_f_dot f0, t_f_dot f1, unsigned int color)
{
    t_f_dot df;
	int		p;
	t_f_dot	f;
	int		inc;
 
	df.fx = f1.fx - f0.fx;
	df.fy = f1.fy - f0.fy;
	inc = 1;
	if (df.fy < 0)
	{
		inc = -1;
		df.fy = df.fy * -1;
	}	
	f = f0;
	p = 2 * df.fy - df.fx;
 	f.color = color;
	while(f.fx < f1.fx)
	{
		my_mlx_pixel_put(data, f);
		if(p >= 0)
		{
			f.fy = f.fy + inc;
			p = p + 2 * (df.fy - df.fx);
		}
		else
			p = p + 2 * df.fy;
		f.fx++;
	}
}

void ft_dline(t_data *data, t_f_dot f0, t_f_dot f1, unsigned int color)
{
	if (abs(f1.fy - f0.fy) < abs (f1.fx - f0.fx))
	{
		if (f0.fx > f1.fx)
			ft_drawline_w(data, f1, f0, color);
		else
			ft_drawline_w(data, f0, f1, color);
	}
	else
	{
		if (f0.fy > f1.fy)
			ft_drawline_h(data, f1, f0, color);
		else
			ft_drawline_h(data, f0, f1, color);
	}	
}

void ft_draw_x_lines(t_fdf *fdf, t_data *img, unsigned int color)
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
				rad, &img->size, img->view_mode), color);			
			j++;
		}
		i++;
	}	
}

void ft_draw_z_lines(t_fdf *fdf, t_data *img, unsigned int color)
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
				img->view_mode), to_f(c_dots[(j + 1) * (fdf->cnt_x) + i], rad,\
				&img->size, img->view_mode), color);
			j++;
		}
		i++;
	}
}

void ft_drawmesh(t_fdf *fdf, t_data *img, unsigned int color)
{
	ft_draw_x_lines(fdf, img, color);
	ft_draw_z_lines(fdf, img, color);
}
