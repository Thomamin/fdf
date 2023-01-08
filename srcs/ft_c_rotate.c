#include <math.h>
#include <stdlib.h>
#include <libft.h>
#include "fdf.h"

void ft_c_x_rotate(t_c_dot *c_dots, double theta)
{
	double	sinTheta;
	double	cosTheta;
	int		y;
	int		z;
	int		i;

	i = 0;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (c_dots->color != 0x3456789A)
	{ 
		y = c_dots->cy;
		z = c_dots->cz;
		c_dots->cy = y * cosTheta - z * sinTheta;
		c_dots->cz = z * cosTheta + y * sinTheta;
		c_dots++;
	}
}

void ft_c_y_rotate(t_c_dot *c_dots, double theta)
{
	double sinTheta;
   	double cosTheta;
	int		x;
	int		z;
	int		i;

	i = 0;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (c_dots->color != 0x3456789A)
	{ 
//		ft_printf("x: %d, y: %d, z: %d \n", c_dots->cx, c_dots->cy, c_dots->cz);
		x = c_dots->cx;
		z = c_dots->cz;
		c_dots->cx = x * cosTheta + z * sinTheta;
		c_dots->cz = z * cosTheta - x * sinTheta;
		c_dots++;
	}
}

void ft_c_z_rotate(t_c_dot *c_dots, double theta)
{
	double	sinTheta;
   	double	cosTheta;
	int		x;
	int		y;
	int		i;

	i = 0;
	sinTheta = sin(theta);
	cosTheta = cos(theta);
	while (c_dots->color != 0x3456789A)
	{ 
		x = c_dots->cx;
		y = c_dots->cy;
		c_dots->cx = x * cosTheta - y * sinTheta;
		c_dots->cy = y * cosTheta + x * sinTheta;
		c_dots++;
	}
}


void ft_c_rotate(t_c_dot *c_dots, int axis, int degree_theta)
{
	double	radian_theta;
	
	radian_theta = (degree_theta % 360) * (M_PI / 180.0);
	if (axis == X_AXIS)
		ft_c_x_rotate(c_dots, radian_theta);
	if (axis == Y_AXIS)
		ft_c_y_rotate(c_dots, radian_theta);
	if (axis == Z_AXIS)
		ft_c_z_rotate(c_dots, radian_theta);
	
}