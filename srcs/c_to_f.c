#include <math.h>
#include "fdf.h"
#include <libft.h>  //-------------------------------------------

// transforms x,y,z coordinates into Flash x coordinate
int	to_fx(t_data *data, t_c_dot dot, double radian, t_f_dot size) 
{
	float xCart;
	int xI;
	// cartesian coordinates
	xCart = (dot.cz - dot.cx) * cos(radian) + dot.cy * 0;
	// flash coordinates
	// xI = xCart + data->line_length / 4 / 2;
	(void) data;
	(void) size;
	xI = xCart;
	return (xI);
}
 
// transforms x,y,z coordinates into Flash y coordinate
int to_fy(t_data *data, t_c_dot dot, double radian, t_f_dot size) 
{
	float yCart;
	int yI;

	// cartesian coordinates
	yCart = dot.cy + (dot.cx + dot.cz) * sin(radian);
	// flash coordinates
	//yI = -yCart + data->line_length / 4 ; //y origin need to be reconsidered 
	(void) data;
	yI = -yCart + size.fy / 2 + 100;
	return (yI);
};

int	to_fx2(t_c_dot dot, double radian) 
{
	float xCart;
	int xI;
	xCart = (dot.cz - dot.cx) * cos(radian) + dot.cy * 0;
	xI = xCart;
	return (xI);
}
 
int to_fy2(t_c_dot dot, double radian) 
{
	float yCart;
	int yI;

	yCart = dot.cy + (dot.cx + dot.cz) * sin(radian);
	yI = -yCart; 
	return (yI);
};

t_f_dot to_f(t_data *data, t_c_dot dot, double radian, t_f_dot size)
{
	t_f_dot f;
	f.fx = to_fx(data, dot, radian, size);
	f.fy = to_fy(data, dot, radian, size);
	return (f);
}