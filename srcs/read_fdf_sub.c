#include <libft.h>
#include "fdf.h"

t_c_dot	*my_set_c_dot(t_c_dot *c_dot, double x, double y, double z)
{
	c_dot->cx = x;
	c_dot->cy = y;
	c_dot->cz = z;
	c_dot->color = 0x0000ff00;
	return (c_dot);
}
