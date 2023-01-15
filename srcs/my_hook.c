#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int	my_close(void *param)
{
	(void) param;
	exit(0);
}

int	key_hook_mng(int keycode, t_data *img)
{
	move_key(keycode, img);
	toggle_modes(keycode, img);
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
	if (mousecode == 2)
		my_close(param);
	return (0);
}

void	my_loop_hook(t_data *img, t_fdf *fdf)
{
	img->fdf = fdf;
	mlx_loop_hook(img->mlx, render_next_frame, img);
}

void	my_hook(t_data *img)
{
	img->x_rot = 0;
	img->y_rot = 0;
	img->times = 1;
	mlx_hook(img->win, 2, 0, key_hook_mng, img);
	mlx_hook(img->win, 5, 0, mouse_hook_mng, img);
	mlx_hook(img->win, 17, 0, my_close, 0);
}
