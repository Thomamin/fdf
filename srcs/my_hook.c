#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int	close(void *param)
{
	(void) param;
	exit(0);
}

int key_hook_mng(int keycode, void *param)
{
	if (keycode == 53)
		close(param);
	return (0);
}

int	mouse_hook_mng(int mousecode, void *param)
{
	if (mousecode == 2)
		close(param);
	return (0);
}

void my_hook(void *win, void *param)
{
	mlx_hook(win, 2, 0, key_hook_mng, param);
	mlx_hook(win, 5, 0, mouse_hook_mng, param);
	mlx_hook(win, 17, 0, close, param);
}


int	render_next_frame(void *mlx, t_fdf *fdata)
{
	t_fdf	*temp;
	void	*tmp;
	tmp = mlx;
	temp = fdata;
	return (0);
}

void my_loop_hook(void *mlx, void *args)
{
	mlx_loop_hook(mlx, render_next_frame, args);
}