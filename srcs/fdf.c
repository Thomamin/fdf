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
	t_args	mlx_arg;
	t_data	img;
	t_fdf	fdf_data;
	double	radian = 0.46365;
	                          atexit(check_leak);//
	if(argc != 2)
	{
		ft_printf("Error: Need fdf input\n");
		return (0);
	}	
	fdf_data.c_dots = NULL;
	ft_read_fdf(&fdf_data, open(argv[1], O_RDONLY), &mlx_arg, &img);	
	ft_c_rotate(&fdf_data, Z_AXIS, 30);
	ft_drawmesh(&fdf_data, &img, radian, 0x00FF0000);
	mlx_put_image_to_window(mlx_arg.mlx, mlx_arg.win, img.img, 0, 0);
	mlx_destroy_image(mlx_arg.mlx, img.img);	
	my_hook(mlx_arg.win, NULL);
	mlx_loop(mlx_arg.mlx);
}
