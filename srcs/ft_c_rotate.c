#include <math.h>
#include "fdf.h"

void	ft_c_x_rotate(t_fdf *fdf, double theta)
{
	double	sin_theta;
	double	cos_theta;
	t_c_dot	*c_dots;
	t_f_dot	f_dot;
	int		i;

	i = 0;
	c_dots = fdf->c_dots;
	sin_theta = sin(theta);
	cos_theta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{
		f_dot.fy = c_dots->cy;
		f_dot.fx = c_dots->cz;
		c_dots->cy = f_dot.fy * cos_theta - f_dot.fx * sin_theta;
		c_dots->cz = f_dot.fx * cos_theta + f_dot.fy * sin_theta;
		c_dots++;
	}
}

void	ft_c_y_rotate(t_fdf *fdf, double theta)
{
	double	sin_theta;
	double	cos_theta;
	t_c_dot	*c_dots;
	t_f_dot	f_dot;
	int		i;

	i = 0;
	c_dots = fdf->c_dots;
	sin_theta = sin(theta);
	cos_theta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{
		f_dot.fx = c_dots->cx;
		f_dot.fy = c_dots->cz;
		c_dots->cx = f_dot.fx * cos_theta + f_dot.fy * sin_theta;
		c_dots->cz = f_dot.fy * cos_theta - f_dot.fx * sin_theta;
		c_dots++;
	}
}

void	ft_c_z_rotate(t_fdf *fdf, double theta)
{
	double	sin_theta;
	double	cos_theta;
	t_c_dot	*c_dots;
	t_f_dot	f_dot;
	int		i;

	i = 0;
	c_dots = fdf->c_dots;
	sin_theta = sin(theta);
	cos_theta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{
		f_dot.fx = c_dots->cx;
		f_dot.fy = c_dots->cy;
		c_dots->cx = f_dot.fx * cos_theta - f_dot.fy * sin_theta;
		c_dots->cy = f_dot.fy * cos_theta + f_dot.fx * sin_theta;
		c_dots++;
	}
}

void	ft_c_rotate(t_fdf *fdf, int axis, int degree_theta)
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
