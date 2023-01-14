#include <math.h>
#include "fdf.h"
#include <libft.h>  //-------------------------------------------

// transforms x,y,z coordinates into Flash x coordinate
int	to_iso_x(t_c_dot dot, double radian, t_imgsz *size) 
{
	double xCart;
	int xI;
	
	xCart = (dot.cz - dot.cx) * cos(radian);
	if (size != NULL)
		xI = xCart - size->min_x + 50; 
	else
		xI = xCart;

	return (xI);
}
 
// transforms x,y,z coordinates into Flash y coordinate
int to_iso_y(t_c_dot dot, double radian, t_imgsz *size) 
{
	double yCart;
	int yI;

	yCart = dot.cy + (dot.cx + dot.cz) * sin(radian);
	if (size != NULL)
		yI = -yCart - size->min_y + 50;
	else
		yI = -yCart;

	return (yI);
};


t_f_dot to_f(t_c_dot dot, double radian, t_imgsz *size)
{
	t_f_dot f;
	f.fx = to_iso_x(dot, radian, size);
	f.fy = to_iso_y(dot, radian, size);
	return (f);
}
