#include <math.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

void ft_c_x_rotate(t_fdf *fdf, double theta)
{
	double	sinTheta;
	double	cosTheta;
	int		y;
	int		z;
	int		i;

	i = 0;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{ 
		y = fdf->c_dots->cy;
		z = fdf->c_dots->cz;
		fdf->c_dots->cy = y * cosTheta - z * sinTheta;
		fdf->c_dots->cz = z * cosTheta + y * sinTheta;
		fdf->c_dots++;
	}
}

void ft_c_y_rotate(t_fdf *fdf, double theta)
{
	double sinTheta;
   	double cosTheta;
	int		x;
	int		z;
	int		i;

	i = 0;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{ 
//		ft_printf("x: %d, y: %d, z: %d \n", c_dots->cx, c_dots->cy, c_dots->cz);
		x = fdf->c_dots->cx;
		z = fdf->c_dots->cz;
		fdf->c_dots->cx = x * cosTheta + z * sinTheta;
		fdf->c_dots->cz = z * cosTheta - x * sinTheta;
		fdf->c_dots++;
	}
}

void ft_c_z_rotate(t_fdf *fdf, double theta)
{
	double	sinTheta;
   	double	cosTheta;
	int		x;
	int		y;
	int		i;

	i = 0;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (i++ < fdf->cnt_x * fdf->cnt_z)
	{ 
		x = fdf->c_dots->cx;
		y = fdf->c_dots->cy;
		fdf->c_dots->cx = x * cosTheta - y * sinTheta;
		fdf->c_dots->cy = y * cosTheta + x * sinTheta;
		fdf->c_dots++;
	}
}


void ft_c_rotate(t_fdf *fdf, int axis, int degree_theta)
{
	double	radian_theta;
	
	radian_theta = (degree_theta % 360) * (M_PI / 180.0);
	if (axis == X_AXIS)
		ft_c_x_rotate(fdf, radian_theta);
	if (axis == Y_AXIS)
		ft_c_y_rotate(fdf, radian_theta);
	if (axis == Z_AXIS)
		ft_c_z_rotate(fdf, radian_theta);
	
}