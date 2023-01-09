#include <mlx.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, t_f_dot f)
{
	char	*dst;

	dst = data->addr + (f.fy * data->line_length + f.fx * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = f.color;
}

void	ft_drawline_h(t_data *data, t_f_dot f0, t_f_dot f1, unsigned int color)
{
    t_f_dot df;
	int		p;
	t_f_dot	f;
	int		inc;
 
	f.color = color;
	df.fx = f1.fx - f0.fx;
	df.fy = f1.fy - f0.fy;
	inc = 1;
	if (df.fx < 0)
	{
		inc = -1;
		df.fx = df.fx * -1;
	}
	f.fx = f0.fx;
	f.fy = f0.fy;
	p = 2 * df.fx - df.fy;
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

void	ft_drawline_w(t_data *data, t_f_dot f0, t_f_dot f1, int color)
{
    t_f_dot df;
	int		p;
	t_f_dot	f;
	int		inc;
 
	f.color = color;
	df.fx = f1.fx - f0.fx;
	df.fy = f1.fy - f0.fy;
	inc = 1;
	if (df.fy < 0)
	{
		inc = -1;
		df.fy = df.fy * -1;
	}	
	f.fx = f0.fx;
	f.fy = f0.fy;
 
	p = 2 * df.fy - df.fx;
 
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

void ft_drawline(t_data *data, t_f_dot f0, t_f_dot f1, unsigned int color)
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

void ft_drawmesh(t_fdf *fdf, t_data *img, double rad, unsigned int color)
{
	int i;
	int	j;
	t_c_dot *c_dots;

	i = 0; 
	c_dots = fdf->c_dots;
	while (i < fdf->cnt_x - 1)
	{
		j = 0;
		while (j < fdf->cnt_z)
		{
			ft_drawline(img, to_f(img, c_dots[j * (fdf->cnt_x) + i], rad), \
			to_f(img, c_dots[j * (fdf->cnt_x) + i + 1], rad), color);
			j++;
		}
		i++;
	}
}

t_args *my_init_mlx_win(t_args *mlx_arg, t_data *img, int size_x, int size_y)
{
	mlx_arg->mlx = mlx_init();
	if(!mlx_arg->mlx)
		ft_printf("Error : Can't connect to the graphical system\n");
	mlx_arg->win = mlx_new_window(mlx_arg->mlx, size_x, size_y, "Hello world!");
	img->img = mlx_new_image(mlx_arg->mlx, size_x, size_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
		ft_printf("dbg 0\n"); //===============================
	return (mlx_arg);
}
