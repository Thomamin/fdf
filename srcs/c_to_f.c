#include <math.h>
#include "fdf.h"
#include <libft.h>  //-------------------------------------------

// transforms x,y,z coordinates into Flash x coordinate
int	to_fx(t_c_dot dot, double radian, t_imgsz *size) 
{
	double xCart;
	int xI;
	
	xCart = (dot.cz - dot.cx) * cos(radian) + dot.cy * 0;
	if (size != NULL)
		xI = xCart - size->min_x + 50; 
	else
		xI = xCart;
	return (xI);
}
 
// transforms x,y,z coordinates into Flash y coordinate
int to_fy(t_c_dot dot, double radian, t_imgsz *size) 
{
	double yCart;
	int yI;

	yCart = dot.cy + (dot.cx + dot.cz) * sin(radian);
	if (size != NULL)
		yI = -yCart + (size->max_y - size->min_y) / 2 + 50;
	else
		yI = -yCart;
	return (yI);
};


t_f_dot to_f(t_c_dot dot, double radian, t_imgsz size)
{
	t_f_dot f;
	f.fx = to_fx(dot, radian, &size);
	f.fy = to_fy(dot, radian, &size);
	
	ft_printf("fx: %d, fy: %d\n", f.fx, f.fy);
	// if (f.fx > size.max_x - size.min_x)
	// 	f.fx = size.max_x - size.min_x;
	// if (f.fx < size.min_x)
	// 	f.fx = 0;;
	// if (f.fy > size.max_y - size.min_y)
	// 	f.fy = size.max_y - size.min_y;
	// if (f.fy < size.min_y)
	// 	f.fy = 0;
	return (f);
}