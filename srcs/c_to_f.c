#include <math.h>
#include "fdf.h"

int	to_iso_x(t_c_dot dot, double radian, t_imgsz *size) 
{
	double xCart;
	int xI;
	
	xCart = (dot.cz - dot.cx) * cos(radian);
	if (size)
		xI = xCart - size->min_x + 50; 
	else
		xI = xCart;

	return (xI);
}
 
int to_iso_y(t_c_dot dot, double radian, t_imgsz *size) 
{
	double yCart;
	int yI;

	yCart = dot.cy + (dot.cx + dot.cz) * sin(radian);
	if (size)
		yI = -yCart - size->min_y + 50;
	else
		yI = -yCart;

	return (yI);
};

void to_onep_x(t_c_dot *dot, t_imgsz *size) 
{
	double	xOnep;
	double	rate;

	(void) size;
	rate = 1 - dot->cz / (size->max_x - size->min_x);
	if (rate < 0)
		rate = 0;
	xOnep = dot->cx * rate;
	dot->cx = xOnep;
}

void to_onep_y(t_c_dot *dot, t_imgsz *size) 
{
	double	yOnep;
	double	rate;

	(void) size;
	rate = 1 - dot->cz / (size->max_x - size->min_x);
	if (rate < 0)
		rate = 0;
	yOnep = dot->cy * rate;
	dot->cy = yOnep;
};


t_f_dot to_f(t_c_dot dot, double radian, t_imgsz *size, int mode)
{
	t_f_dot f;

	if (mode == 1)
	{
		to_onep_x(&dot, size);
		to_onep_y(&dot, size);
	}
	f.fx = to_iso_x(dot, radian, size);
	f.fy = to_iso_y(dot, radian, size);
	return (f);
}
