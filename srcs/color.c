/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:40:29 by dmin              #+#    #+#             */
/*   Updated: 2023/01/16 11:40:35 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned int	my_get_color(t_imgsz size, int cy)
{
	unsigned int	ret;
	unsigned int	clr[8];
	double			rel_y_pos;

	clr[0] = (0x40 << 16) | (0x50 << 8) | 0x70;
	clr[1] = (0x40 << 16) | (0xa0 << 8) | 0xff;
	clr[2] = (0x60 << 16) | (0xa0 << 8) | 0xff;
	clr[3] = (0x60 << 16) | (0xd0 << 8) | 0xff;
	clr[4] = (0xc0 << 16) | (0x70 << 8) | 0xff;
	clr[5] = (0xc0 << 16) | (0xf0 << 8) | 0xff;
	clr[6] = (0xff << 16) | (0xe0 << 8) | 0xff;
	clr[7] = (0xff << 16) | (0xff << 8) | 0xff;
	rel_y_pos = (cy - size.min_cy) / (size.max_cy - size.min_cy);
	if (rel_y_pos < 0.25)
		ret = (rel_y_pos) * 4 * (clr[1] - clr[0]) + clr[0];
	else if (rel_y_pos < 0.5)
		ret = (rel_y_pos - 0.25) * 4 * (clr[3] - clr[2]) + clr[2];
	else if (rel_y_pos < 0.75)
		ret = (rel_y_pos - 0.5) * 4 * (clr[5] - clr[4]) + clr[4];
	else
		ret = (rel_y_pos - 0.75) * 4 * (clr[7] - clr[6]) + clr[6];
	return (ret);
}

void	my_fdf_coloring(t_data *img, t_fdf *fdf, int c_mode)
{
	int				i;
	unsigned int	set_color;
	t_c_dot			*c_dots;

	i = 0;
	c_dots = fdf->c_dots;
	while (i < fdf->cnt_x * fdf->cnt_z)
	{
		if (c_mode)
			set_color = my_get_color(img->size, c_dots[i].cy);
		else
			set_color = 0x0000ff00;
		c_dots[i].color = set_color;
		i++;
	}
}
