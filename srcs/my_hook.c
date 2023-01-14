#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

#include <stdio.h>

int my_close(void *param)
{
	(void) param;
	exit(0);
}

int key_hook_mng(int keycode, t_data *img)
{
	if (keycode == 126)
		img->x_rot = 5;
	if (keycode == 125)
		img->x_rot = -5;
	if (keycode == 124)
		img->y_rot = 5;
	if (keycode == 123)
		img->y_rot = -5;
	if (keycode == 13)
		img->times = 1.2;
	if (keycode == 1)
		img->times = 0.8;
	if (keycode == 53)
		my_close(img);
	return (0);
}

int	mouse_hook_mng(int mousecode, void *param)
{
	(void) param;
	if (mousecode == 2)
		my_close(param);
	return (0);
}

int	render_next_frame(t_data *img)
{
	int width;
	int height;

	width = img->size.max_x - img->size.min_x + 100;
	height = img->size.max_y - img->size.min_y + 100;
	ft_c_move(img->fdf, -(img->size.mn_cx + img->size.mx_cx) / 2, -(img->size.mn_cy + img->size.mx_cy) / 2, -(img->size.mn_cz + img->size.mx_cz) / 2);
	ft_c_zoom(img->fdf, 1000);
	ft_c_rotate(img->fdf, X_AXIS, img->x_rot);
	ft_c_rotate(img->fdf, Y_AXIS, img->y_rot);
	ft_c_zoom(img->fdf, img->times);
	ft_c_zoom(img->fdf, 0.001);
	ft_c_move(img->fdf, (img->size.mx_cx + img->size.mn_cx) / 2, (img->size.mx_cy + img->size.mn_cy) / 2, (img->size.mx_cz + img->size.mn_cz) / 2);
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
										&img->line_length, &img->endian);
	ft_drawmesh(img->fdf, img, 0x0000FF00);
	ft_draw_axis(img, img->radian, img->size);
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	img->x_rot = 0;
	img->y_rot = 0;
	img->times = 1;
	return (0);
}

void my_loop_hook(t_data *img, t_fdf *fdf)
{
	img->fdf = fdf;
	mlx_loop_hook(img->mlx, render_next_frame, img);
}

void my_hook(t_data *img)
{
	img->x_rot = 0;
	img->y_rot = 0;
	img->times = 1;
	mlx_hook(img->win, 2, 0, key_hook_mng, img);
	mlx_hook(img->win, 5, 0, mouse_hook_mng, img);
	mlx_hook(img->win, 17, 0, my_close, 0);
}
