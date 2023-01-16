/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:41:45 by dmin              #+#    #+#             */
/*   Updated: 2023/01/16 11:42:17 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_c_zoom(t_fdf *fdf, float times)
{
	int		i;
	t_c_dot	*c_dots;

	c_dots = fdf->c_dots;
	i = 0;
	if (times <= 0)
		times = 1;
	while (i++ < fdf->cnt_x * fdf->cnt_z && times != 1)
	{
		c_dots->cx = c_dots->cx * times;
		c_dots->cy = c_dots->cy * times;
		c_dots->cz = c_dots->cz * times;
		c_dots++;
	}
}

void	ft_c_move(t_fdf *fdf, double xm, double ym, double zm)
{
	int		i;
	t_c_dot	*c_dots;

	c_dots = fdf->c_dots;
	i = 0;
	if (xm != 0 || ym != 0 || zm != 0)
	{
		while (i++ < fdf->cnt_x * fdf->cnt_z)
		{
			c_dots->cx = c_dots->cx + xm;
			c_dots->cy = c_dots->cy + ym;
			c_dots->cz = c_dots->cz + zm;
			c_dots++;
		}
	}
}
