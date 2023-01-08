#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, t_f_dot f)
{
	char	*dst;

	dst = data->addr + (f.fy * data->line_length + f.fx * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = f.color;
}

void	ft_drawline_h(t_data *data, t_f_dot f0, t_f_dot f1, int color)
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

void ft_drawline(t_data *data, t_f_dot f0, t_f_dot f1, int color)
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