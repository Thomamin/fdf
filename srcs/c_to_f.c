#include <math.h>
#include "fdf.h"

int	to_iso_x(t_c_dot dot, double radian, t_imgsz *size)
{
	double	xcart;
	int		xi;

	xcart = (dot.cz - dot.cx) * cos(radian);
	if (size)
		xi = xcart - size->min_x + 50;
	else
		xi = xcart;
	return (xi);
}

int	to_iso_y(t_c_dot dot, double radian, t_imgsz *size)
{
	double	ycart;
	int		yi;

	ycart = dot.cy + (dot.cx + dot.cz) * sin(radian);
	if (size)
		yi = -ycart - size->min_y + 50;
	else
		yi = -ycart;
	return (yi);
}

void	to_onep_x(t_c_dot *dot, t_imgsz *size)
{
	double	xonep;
	double	rate;

	rate = 1 - dot->cz / (size->max_x - size->min_x);
	if (rate < 0)
		rate = 0;
	xonep = dot->cx * rate;
	dot->cx = xonep;
}

void	to_onep_y(t_c_dot *dot, t_imgsz *size)
{
	double	yonep;
	double	rate;

	rate = 1 - dot->cz / (size->max_x - size->min_x);
	if (rate < 0)
		rate = 0;
	yonep = dot->cy * rate;
	dot->cy = yonep;
}

t_f_dot	to_f(t_c_dot dot, double radian, t_imgsz *size, int mode)
{
	t_f_dot	f;

	if (mode == 1)
	{
		to_onep_x(&dot, size);
		to_onep_y(&dot, size);
	}
	f.fx = to_iso_x(dot, radian, size);
	f.fy = to_iso_y(dot, radian, size);
	f.color = dot.color;
	return (f);
}
