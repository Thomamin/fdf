#include <math.h>
#include "fdf.h"
#include <libft.h>  //-------------------------------------------

// transforms x,y,z coordinates into Flash x coordinate
int	to_fx(t_data *data, t_c_dot dot, double radian) 
{
	float xCart;
	int xI;
	// cartesian coordinates
	xCart = (dot.cx - dot.cz) * cos(radian) + dot.cy * 0;
	// flash coordinates
	xI = xCart + data->line_length / 4 / 2;
	return (xI);
}
 
// transforms x,y,z coordinates into Flash y coordinate
int to_fy(t_data *data, t_c_dot dot, double radian) 
{
	float yCart;
	int yI;

	// cartesian coordinates
	yCart = dot.cy + (dot.cx + dot.cz) * sin(radian);
	// flash coordinates
	yI = -yCart + data->line_length / 4 - 100; //y origin need to be reconsidered 
	return (yI);
};

t_f_dot to_f(t_data *data, t_c_dot dot, double radian)
{
	t_f_dot f;
	ft_printf("x: %d, y: %d, z: %d\n", dot.cx, dot.cy, dot.cz);
	f.fx = to_fx(data, dot, radian);
	f.fy = to_fy(data, dot, radian);
	return (f);
}