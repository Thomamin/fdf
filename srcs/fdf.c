/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:28:33 by dmin              #+#    #+#             */
/*   Updated: 2023/01/04 12:28:40 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>
#include "fdf.h"

void check_leak(void)
{
	system("leaks fdf");
}

t_f_dot my_get_img_size(t_fdf *fdf, double radian)
{
	int		i;
	int		len;
	t_f_dot	fdot[2];

	i = 0;
	len = fdf->cnt_x * fdf->cnt_z;
	fdot[0].fx = 0;
	fdot[0].fy = 0;
	fdot[1].fx = 0;
	fdot[1].fy = 0;
	while (i++ < len)
	{
		if (to_fx2(fdf->c_dots[i], radian) < fdot[0].fx)
			fdot[0].fx = to_fx2(fdf->c_dots[i], radian);
		if (to_fx2(fdf->c_dots[i], radian) > fdot[1].fx)
			fdot[1].fx = to_fx2(fdf->c_dots[i], radian);
		if (to_fy2(fdf->c_dots[i], radian) < fdot[0].fy)
			fdot[0].fy = to_fy2(fdf->c_dots[i], radian);
		if (to_fy2(fdf->c_dots[i], radian) > fdot[1].fy)
			fdot[1].fy = to_fy2(fdf->c_dots[i], radian);		
	}
	ft_printf("minx: %d, maxx: %d, miny: %d, maxy: %d\n", fdot[0].fx, fdot[1].fx, fdot[0].fy, fdot[1].fy);	
	fdot[1].fx = abs(fdot[1].fx - fdot[0].fx);
	fdot[1].fy = abs(fdot[1].fy - fdot[0].fy);
	return (fdot[1]);
}

t_args *my_init_mlx_win(t_args *mlx_arg, t_data *img, t_f_dot size)
{
	int width;
	int height;

	width = size.fx + 100;
	height = size.fy + 100;
	mlx_arg->mlx = mlx_init();
	if(!mlx_arg->mlx)
		return(ft_err_mng(20, "Can't connect graphical system", NULL, NULL));
	mlx_arg->win = mlx_new_window(mlx_arg->mlx, width, height, "Hello world!");
	img->img = mlx_new_image(mlx_arg->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
							&img->line_length, &img->endian);
	return (mlx_arg);
}

int	main(int argc, char **argv)
{
	t_args	mlx_arg;
	t_data	img;
	t_fdf	fdf_data;
	t_f_dot	size;
	double	radian;
	                          atexit(check_leak);
	radian = 0.46365;						  
	fdf_data.c_dots = NULL;
	if(argc != 2)
	{
		ft_printf("Err(10): Need fdf input");
		return (10);
	}
	fdf_data.c_dots = ft_read_fdf(&fdf_data, open(argv[1], O_RDONLY));
	if (!fdf_data.c_dots)
		return (10);
	ft_c_zoom(&fdf_data, 10);
	ft_c_rotate(&fdf_data, Y_AXIS, -90);
	size = my_get_img_size(&fdf_data, radian);
	my_init_mlx_win(&mlx_arg, &img, size);
	ft_drawmesh(&fdf_data, &img, radian, 0x00FF0000, size);
	mlx_put_image_to_window(mlx_arg.mlx, mlx_arg.win, img.img, 0, 0);
	mlx_destroy_image(mlx_arg.mlx, img.img);	
	my_hook(mlx_arg.win, NULL);
	mlx_loop(mlx_arg.mlx);
	free(fdf_data.c_dots);
	return (0);
}
