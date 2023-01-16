/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:40:42 by dmin              #+#    #+#             */
/*   Updated: 2023/01/16 11:40:50 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	my_mlx_pixel_put(t_data *img, t_f_dot f)
{
	char	*dst;

	dst = NULL;
	if (f.fx > 0 && f.fx < img->size.max_x - img->size.min_x + 100 \
			&& f.fy < img->size.max_y - img->size.min_y + 100 && f.fy > 0)
	{
		dst = img->addr + (f.fy * img->line_length \
								+ f.fx * (img->bits_per_pixel / 8));
		*(unsigned int *) dst = f.color;
	}
}

void	ft_drawline_h(t_data *data, t_f_dot f0, t_f_dot f1)
{
	t_f_dot	f[3];

	f[0].fx = f1.fx - f0.fx;
	f[0].fy = f1.fy - f0.fy;
	f[2].fx = 1;
	if (f[0].fx < 0)
	{
		f[2].fx = -1;
		f[0].fx = f[0].fx * -1;
	}
	f[1] = f0;
	f[2].fy = 2 * f[0].fx - f[0].fy;
	while (f[1].fy < f1.fy)
	{
		my_mlx_pixel_put(data, f[1]);
		if (f[2].fy >= 0)
		{
			f[1].fx = f[1].fx + f[2].fx;
			f[2].fy = f[2].fy + 2 * (f[0].fx - f[0].fy);
		}
		else
			f[2].fy = f[2].fy + 2 * f[0].fx;
		f[1].fy++;
	}
}

void	ft_drawline_w(t_data *data, t_f_dot f0, t_f_dot f1)
{
	t_f_dot	f[3];

	f[0].fx = f1.fx - f0.fx;
	f[0].fy = f1.fy - f0.fy;
	f[2].fx = 1;
	if (f[0].fy < 0)
	{
		f[2].fx = -1;
		f[0].fy = f[0].fy * -1;
	}	
	f[1] = f0;
	f[2].fy = 2 * f[0].fy - f[0].fx;
	while (f[1].fx < f1.fx)
	{
		my_mlx_pixel_put(data, f[1]);
		if (f[2].fy >= 0)
		{
			f[1].fy = f[1].fy + f[2].fx;
			f[2].fy = f[2].fy + 2 * (f[0].fy - f[0].fx);
		}
		else
			f[2].fy = f[2].fy + 2 * f[0].fy;
		f[1].fx++;
	}
}

void	ft_dline(t_data *data, t_f_dot f0, t_f_dot f1)
{
	if (abs(f1.fy - f0.fy) < abs (f1.fx - f0.fx))
	{
		if (f0.fx > f1.fx)
			ft_drawline_w(data, f1, f0);
		else
			ft_drawline_w(data, f0, f1);
	}
	else
	{
		if (f0.fy > f1.fy)
			ft_drawline_h(data, f1, f0);
		else
			ft_drawline_h(data, f0, f1);
	}
}
