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


//---------
void ft_draw_axis(t_data *img, double rad, t_imgsz size)
{
	t_c_dot s_dot;
	t_c_dot e_dot;

	s_dot.cx = (size.max_x - size.min_x) / 3;
	s_dot.cy = 0;
	s_dot.cz = 0;
	e_dot =  s_dot;
	e_dot.cx = 0;
	ft_drawline(img, to_f(s_dot, rad, size), to_f(e_dot, rad, size), 0x77550000);
	s_dot.cx = 0;
	s_dot.cy = (size.max_y - size.min_y ) / 2;
	s_dot.cz = 0;
	e_dot =  s_dot;
	e_dot.cy = 0;
	ft_drawline(img, to_f(s_dot, rad, size), to_f(e_dot, rad, size), 0x77005500);
	s_dot.cx = 0;
	s_dot.cy = 0;
	s_dot.cz = (size.max_x - size.min_x)/ 3;
	e_dot =  s_dot;
	e_dot.cz = 0;
	ft_drawline(img, to_f(s_dot, rad, size), to_f(e_dot, rad, size), 0x77000055);
}
//---------------

void check_leak(void)
{
	system("leaks fdf");
}

t_imgsz my_get_img_size(t_fdf *fdf, double radian)
{
	int		i;
	int		len;
	t_imgsz	size;

	i = 0;
	len = fdf->cnt_x * fdf->cnt_z;
	size.min_x = 0;
	size.min_y = 0;
	size.max_x = 0;
	size.max_y = 0;
	while (i < len)
	{
		if (to_fx(fdf->c_dots[i], radian, NULL) < size.min_x)
			size.min_x = to_fx(fdf->c_dots[i], radian, NULL);
		if (to_fx(fdf->c_dots[i], radian, NULL) > size.max_x)
			size.max_x = to_fx(fdf->c_dots[i], radian, NULL);
		if (to_fy(fdf->c_dots[i], radian, NULL) < size.min_y)
			size.min_y = to_fy(fdf->c_dots[i], radian, NULL);
		if (to_fy(fdf->c_dots[i], radian, NULL) > size.max_y)
			size.max_y = to_fy(fdf->c_dots[i], radian, NULL);		
		i++;
	}
	ft_printf("\nminx: %d, maxx: %d, miny: %d, maxy: %d\n", \
					size.min_x, size.max_x, size.min_y, size.max_y);	
	return (size);
}

t_args *my_init_mlx_win(t_args *mlx_arg, t_data *img, t_imgsz size)
{
	int width;
	int height;

	width = size.max_x - size.min_x + 100;
	height = size.max_y - size.min_y + 100;
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
	t_imgsz	size;
	double	radian;
	                          atexit(check_leak);
	radian = 0.46365;						  
	fdf_data.c_dots = NULL;
	if(argc != 2)
	{
		ft_printf("Err(10): Need fdf input\n");
		return (-1);
	}
	fdf_data.c_dots = ft_read_fdf(&fdf_data, open(argv[1], O_RDONLY));
	if (!fdf_data.c_dots)
		return (-1);
	ft_c_zoom(&fdf_data, 10);
	ft_c_rotate(&fdf_data, Y_AXIS, -90);
	size = my_get_img_size(&fdf_data, radian);
	my_init_mlx_win(&mlx_arg, &img, size);
	ft_printf("line_len : %d, bits per pixel: %d\n", img.line_length, img.bits_per_pixel);
	//----------
	ft_draw_axis(&img, radian, size);	

	//----------
	ft_drawmesh(&fdf_data, &img, radian, 0x0000FF00, size);
	mlx_put_image_to_window(mlx_arg.mlx, mlx_arg.win, img.img, 0, 0);
	mlx_destroy_image(mlx_arg.mlx, img.img);	
	my_hook(mlx_arg.win, NULL);
	mlx_loop(mlx_arg.mlx);
	free(fdf_data.c_dots);
	return (0);
}
