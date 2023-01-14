#include <math.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

void ft_c_x_rotate(t_fdf *fdf, double theta)
{
	double	sinTheta;
	double	cosTheta;
	t_c_dot	*c_dots;
	t_f_dot	f_dot;
	int		i;

	i = 0;
	c_dots = fdf->c_dots;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{ 
		f_dot.fy = c_dots->cy;
		f_dot.fx = c_dots->cz;
		c_dots->cy = f_dot.fy * cosTheta - f_dot.fx * sinTheta;
		c_dots->cz = f_dot.fx * cosTheta + f_dot.fy * sinTheta;
		c_dots++;
	}
}

void ft_c_y_rotate(t_fdf *fdf, double theta)
{
	double	sinTheta;
   	double	cosTheta;
	t_c_dot	*c_dots;
	t_f_dot	f_dot;
	int		i;

	i = 0;
	c_dots = fdf->c_dots;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{ 
		f_dot.fx = c_dots->cx;
		f_dot.fy = c_dots->cz;
		c_dots->cx = f_dot.fx * cosTheta + f_dot.fy * sinTheta;
		c_dots->cz = f_dot.fy * cosTheta - f_dot.fx * sinTheta;
		c_dots++;
	}
}

void ft_c_z_rotate(t_fdf *fdf, double theta)
{
	double	sinTheta;
   	double	cosTheta;
	t_c_dot	*c_dots;
	t_f_dot	f_dot;
	int		i;

	i = 0;
	c_dots = fdf->c_dots;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{ 
		f_dot.fx = c_dots->cx;
		f_dot.fy = c_dots->cy;
		c_dots->cx = f_dot.fx * cosTheta - f_dot.fy * sinTheta;
		c_dots->cy = f_dot.fy * cosTheta + f_dot.fx * sinTheta;
		c_dots++;
	}
}


void ft_c_rotate(t_fdf *fdf, int axis, int degree_theta)
{
	double	radian_theta;

	if (degree_theta != 0)	
	{
		radian_theta = (degree_theta % 360) * (M_PI / 180.0);
		if (axis == X_AXIS)
			ft_c_x_rotate(fdf, radian_theta);
		if (axis == Y_AXIS)
			ft_c_y_rotate(fdf, radian_theta);
		if (axis == Z_AXIS)
			ft_c_z_rotate(fdf, radian_theta);
	}
}

void ft_c_zoom(t_fdf *fdf, float times)
{
	int		i;
	t_c_dot	*c_dots;

	c_dots = fdf->c_dots;
	i = 0;
	if (times <= 0)
		times = 1;
	while (i++ < fdf->cnt_x * fdf->cnt_z && times != 1)
	{
		c_dots->cx = c_dots->cx * times;
		c_dots->cy = c_dots->cy * times;
		c_dots->cz = c_dots->cz * times;
		c_dots++;
	}
}

void ft_c_move(t_fdf *fdf, double xm, double ym, double zm)
{
	int		i;
	t_c_dot *c_dots;

	c_dots = fdf->c_dots;
	i = 0;
	if (xm != 0 || ym != 0 || zm!= 0)
	{
		while (i++ < fdf->cnt_x * fdf->cnt_z)
		{
			c_dots->cx = c_dots->cx + xm;
			c_dots->cy = c_dots->cy + ym;
			c_dots->cz = c_dots->cz + zm;	
			c_dots++;
		}
	}
}
