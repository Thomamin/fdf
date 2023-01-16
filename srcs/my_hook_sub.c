/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_hook_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:41:20 by dmin              #+#    #+#             */
/*   Updated: 2023/01/16 11:41:31 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	move_key(int keycode, t_data *img)
{
	if (keycode == 32)
		img->x_mv = 10;
	if (keycode == 37)
		img->x_mv = -10;
	if (keycode == 34)
		img->y_mv = 10;
	if (keycode == 40)
		img->y_mv = -10;
	if (keycode == 31)
		img->z_mv = 10;
	if (keycode == 38)
		img->z_mv = -10;
}

void	toggle_modes(int keycode, t_data *img)
{
	if (keycode == 0)
	{
		if (img->draw_axis == 0)
			img->draw_axis = 1;
		else
			img->draw_axis = 0;
	}
	if (keycode == 9)
	{
		if (img->view_mode == 0)
			img->view_mode = 1;
		else
			img->view_mode = 0;
	}
	if (keycode == 8)
	{
		if (img->color_mode == 0)
			img->color_mode = 1;
		else
			img->color_mode = 0;
		my_fdf_coloring(img, img->fdf, img->color_mode);
	}
}

void	reset_ui_input(t_data *img)
{
	img->x_rot = 0;
	img->y_rot = 0;
	img->x_mv = 0;
	img->y_mv = 0;
	img->z_mv = 0;
	img->times = 1;
}

int	render_next_frame(t_data *img)
{
	int	width;
	int	height;

	width = img->size.max_x - img->size.min_x + 100;
	height = img->size.max_y - img->size.min_y + 100;
	ft_c_move(img->fdf, img->x_mv, img->y_mv, img->z_mv);
	ft_c_move(img->fdf, -(img->size.mid_cx), -(img->size.mid_cy), \
											-(img->size.mid_cz));
	ft_c_zoom(img->fdf, 1000);
	ft_c_rotate(img->fdf, X_AXIS, img->x_rot);
	ft_c_rotate(img->fdf, Y_AXIS, img->y_rot);
	ft_c_zoom(img->fdf, img->times);
	ft_c_zoom(img->fdf, 0.001);
	ft_c_move(img->fdf, img->size.mid_cx, img->size.mid_cy, img->size.mid_cz);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
										&img->line_length, &img->endian);
	ft_drawmesh(img->fdf, img);
	if (img->draw_axis)
		ft_draw_axis(img, img->radian, img->size);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	reset_ui_input(img);
	return (0);
}
