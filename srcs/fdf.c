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
#include <stdlib.h>
#include <fcntl.h>
#include <libft.h>
#include "fdf.h"

void check_leak(void)
{
	system("leaks fdf");
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_c_dot c;
	t_f_dot	f;
	t_fdf	*fdf_data;
	double	radian = 0.46365;

	                          atexit(check_leak);//
	if(argc != 2)
	{
		ft_printf("Error: Need fdf input\n");
		return (0);
	}
	mlx = mlx_init();
	if(!mlx)
		ft_printf("Error : Can't connect to the graphical system\n");
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	fdf_data = ft_read_fdf(open(argv[1], O_RDONLY), &img);


	for (c.cy = 0; c.cy <= 100; c.cy++)
	{
		for (c.cx = 0; c.cx <= 500; c.cx++)
		{
			for (c.cz = 0; c.cz <= 500; c.cz++)
			{
				if ((c.cx % 50 == 0 || c.cz % 50 == 0 ) && c.cy % 50 == 0)
				{	
					f = to_f(&img, &c, radian);
					if(c.cy == 0)
						f.color = 0x0000AA00;
					if(c.cy == 50)
						f.color = 0x88553377;
					if(c.cy == 100)
						f.color = 0x880000AA;
					my_mlx_pixel_put(&img, f);
				}
			}
		}
	}
	t_c_dot *c_dots;
	c_dots = (t_c_dot *)ft_calloc(12, sizeof(t_c_dot));

	c_dots[0].cx = 0;
	c_dots[0].cy = 0;
	c_dots[0].cz = 0;

	c_dots[1].cx = 100;
	c_dots[1].cy = 0;
	c_dots[1].cz = 0;
	
	c_dots[2].cx = 100;
	c_dots[2].cy = 100;
	c_dots[2].cz = 0;
	
	c_dots[3].cx = 0;
	c_dots[3].cy = 100;
	c_dots[3].cz = 0;
	
	c_dots[4].cx = 0;
	c_dots[4].cy = 100;
	c_dots[4].cz = 100;
	
	c_dots[5].cx = 0;
	c_dots[5].cy = 0;
	c_dots[5].cz = 100;

	c_dots[6].cx = 0;
	c_dots[6].cy = 0;
	c_dots[6].cz = 0;

	c_dots[7].cx = 0;
	c_dots[7].cy = 100;
	c_dots[7].cz = 0;

	c_dots[8].cx = 100;
	c_dots[8].cy = 100;
	c_dots[8].cz = 0;

	c_dots[9].cx = 100;
	c_dots[9].cy = 100;
	c_dots[9].cz = 100;

	c_dots[10].cx = 0;
	c_dots[10].cy = 100;
	c_dots[10].cz = 100;

	c_dots[11].color = 0x3456789A;

	//3d cartesian axis rotate
	ft_c_rotate(c_dots, Z_AXIS, 30);
	
	t_f_dot s_dot;  //
	t_f_dot e_dot;  //

	for (int i = 0 ; i < 10; i++)
	{
		ft_drawline(&img, to_f(&img, &c_dots[i], radian), to_f(&img, &c_dots[i+1], radian), 0x00FF0000);

		s_dot = to_f(&img, &c_dots[i], radian);
		e_dot = to_f(&img, &c_dots[i+1], radian);		
		ft_printf("s_x: %d, s_y: %d, e_x: %d, e_y: %d\n", s_dot.fx, s_dot.fy, e_dot.fx, e_dot.fy);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_destroy_image(mlx, img.img);
	
	my_hook(mlx_win, NULL);
	mlx_loop(mlx);
}