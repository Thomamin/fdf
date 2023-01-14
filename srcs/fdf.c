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

void ft_draw_axis(t_data *img, double rad, t_imgsz size)
{
	t_c_dot s_dot;
	t_c_dot e_dot;

	s_dot.cx = -5000;
	s_dot.cy = img->size.mid_cy;
	s_dot.cz = img->size.mid_cz;
	e_dot =  s_dot;
	e_dot.cx = 5000;
	ft_dline(img, to_f(s_dot, rad, &size, img->view_mode), \
		to_f(e_dot, rad, &size, img->view_mode), 0x00FF0000);
	s_dot.cx = img->size.mid_cx;
	s_dot.cy = -5000;
	s_dot.cz = img->size.mid_cz;
	e_dot =  s_dot;
	e_dot.cy = 5000;
	ft_dline(img, to_f(s_dot, rad, &size, img->view_mode), \
		to_f(e_dot, rad, &size, img->view_mode), 0x0000FF00);
	s_dot.cx = img->size.mid_cx;
	s_dot.cy = img->size.mid_cy;
	s_dot.cz = -5000;
	e_dot =  s_dot;
	e_dot.cz = 5000;
	ft_dline(img, to_f(s_dot, rad, &size, img->view_mode), \
		to_f(e_dot, rad, &size, img->view_mode), 0x000000FF);
}

void check_leak(void)
{
	system("leaks fdf");
}

void my_get_c_mids(t_c_dot c_dot, t_imgsz *size, t_c_dot *min, t_c_dot *max)
{
	if(c_dot.cx < min->cx)
		min->cx = c_dot.cx;
	if(c_dot.cx > max->cx)
		max->cx = c_dot.cx;
	if(c_dot.cy < min->cy)
		min->cy = c_dot.cy;
	if(c_dot.cy > max->cy)
		max->cy = c_dot.cy;
	if(c_dot.cz < min->cz)
		min->cz = c_dot.cz;
	if(c_dot.cz > max->cz)
		max->cz = c_dot.cz;
	size->mid_cx = (min->cx + max->cx) / 2;
	size->mid_cy = (min->cy + max->cy) / 2;
	size->mid_cz = (min->cz + max->cz) / 2;
}

void my_get_img_limit(t_c_dot c_dot, t_data *img)
{
	t_f_dot f_dot;

	f_dot = to_f(c_dot, img->radian, NULL, img->view_mode); 
	if (f_dot.fx < img->size.min_x)
		img->size.min_x = f_dot.fx;
	if (f_dot.fx > img->size.max_x)
		img->size.max_x = f_dot.fx;
	if (f_dot.fy < img->size.min_y)
		img->size.min_y = f_dot.fy;
	if (f_dot.fy > img->size.max_y)
		img->size.max_y = f_dot.fy;

}

void my_get_img_size(t_fdf *fdf, t_data *img)
{
	int		i;
	t_c_dot	*c_dots;
	t_c_dot	c_min;
	t_c_dot	c_max;
	
	c_min.cx = 0;
	c_min.cy = 0;
	c_min.cz = 0;
	c_max = c_min;
	i = 0;
	c_dots = fdf->c_dots; 
	while (i < fdf->cnt_x * fdf->cnt_z)
	{
		my_get_img_limit(c_dots[i], img);
		my_get_c_mids(c_dots[i], &img->size, &c_min, &c_max);		
		i++;
	}
// printf("min x: %f, min y: %f, min z: %f, max x: %f, max y: %f, max z: %f\n", img->size.mn_cx, img->size.mn_cy, img->size.mn_cz, img->size.mx_cx, img->size.mx_cy, img->size.mx_cz);
// printf("x move: %f, y move: %f, z move: %f\n", (img->size.mn_cx - img->size.mx_cx) / 2, (img->size.mn_cy - img->size.mx_cy) / 2, (img->size.mn_cz - img->size.mx_cz) / 2);
}

t_data *my_init_mlx_win(t_data *img)
{
	int width;
	int height;

	width = img->size.max_x - img->size.min_x + 100;
	height = img->size.max_y - img->size.min_y + 100;
	if (width > 4000)
		width = 4000;
	if (height > 2000)
		height = 2000;
	img->mlx = mlx_init();
	if(!img->mlx)
		return(ft_err_mng(20, "Can't connect graphical system", NULL, NULL));
	img->win = mlx_new_window(img->mlx, width, height, "dmin's FDF");
	img->img = mlx_new_image(img->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
							&img->line_length, &img->endian);
	return (img);
}

void my_img_data_init(t_data *img)
{
	img->radian = 0.46365;
	img->times = 1;
	img->x_rot = 0;
	img->y_rot = 0;
	img->draw_axis = 0;
	img->size.min_x = 0;
	img->size.min_y = 0;
	img->size.max_x = 0;
	img->size.max_y = 0;
	img->size.mid_cx = 0;
	img->size.mid_cy = 0;
	img->size.mid_cz = 0;
	img->view_mode = 0;
}

int	main(int argc, char **argv)
{
	t_data	img;
	t_fdf	fdf_data;
	                          atexit(check_leak);
	my_img_data_init(&img); 
	fdf_data.c_dots = NULL;
	if(argc != 2)
	{
		ft_printf("Err(10): Need fdf input\n");
		return (-1);
	}
	fdf_data.c_dots = ft_read_fdf(&fdf_data, open(argv[1], O_RDONLY));
	if (!fdf_data.c_dots)
		return (-1);
	ft_c_zoom(&fdf_data, 400 / fdf_data.cnt_z);
	ft_c_rotate(&fdf_data, Y_AXIS, -90);
	my_get_img_size(&fdf_data, &img);
	my_init_mlx_win(&img);
	my_hook(&img);
	my_loop_hook(&img, &fdf_data);
	mlx_loop(img.mlx);
	mlx_destroy_image(img.mlx, img.img);	
	free(fdf_data.c_dots);
	return (0);
}
