#include <libft.h>
#include <mlx.h>
#include "fdf.h"

t_c_dot *my_set_c_dot(t_c_dot *c_dot, int x, int y, int z, unsigned int color)
{
				ft_printf("x: %d, y: %d, z: %d, color: %d\n", x, y, z, color);
	c_dot->cx = x;
	c_dot->cy = y;
	c_dot->cz = z;
	c_dot->color = color;
	return (c_dot);
}

int	ft_get_fdf_line_len(char **data_line)
{
	int len;

	len = 0;
	while (data_line[len] != NULL)
		len++;
	ft_printf("data_len: %d \n", len);
	return (len - 1);
}

void ft_free_multi_arr(char **data_line)
{
	int len;

	len = 0;
	while(data_line[len])
	{
		free(data_line[len++]);
	}
	free(data_line);
}

t_c_dot *fdf_conc_data(t_c_dot *mem1, t_c_dot *mem2, size_t linelen, size_t lines)
{
	size_t line_data_size;
	t_c_dot *ret;

	line_data_size = linelen * sizeof(t_c_dot);

	ret = (t_c_dot *)ft_calloc(lines + 1, line_data_size);
	if (!ret)
		return (NULL);
	if(mem1)
		ft_memcpy(ret, mem1, line_data_size * lines);
	ft_memcpy(ret + line_data_size * lines, mem2, line_data_size);

	for (unsigned long i = linelen * lines; i < linelen * (lines + 1); i++)
	{
		ft_printf("ret[%d], %d, %d, %d \n", i, ret[i].cx, ret[i].cy, ret[i].cz);
	}
	ft_printf("end\n");


	if(mem1)
		free(mem1);
	free(mem2);
	return(ret);
}

void ft_read_fdf(t_fdf *fdf, int fd, t_args *mlx_arg, t_data *img)
{
	int		linelen[2];
	char	*readline;      // gnl로 읽은 문자열
	char	**data_line;	// readline을 split으로 나눈 문자열 배열
	t_c_dot	*new_line;		// data_line을 3차원 좌표로 변환한 좌표 구조체 배열 
	int		cnt_x;
	int		cnt_z;
	

	linelen[0] = 0;
	readline = get_next_line(fd);
	cnt_z = 0;
	while (readline != NULL)
	{	
		data_line = ft_split(readline, ' ');
		linelen[1] = ft_get_fdf_line_len(data_line);
		if(linelen[0] != linelen[1] && linelen[0] != 0)
		{
			ft_printf("Error: fdf input widths different");
//			return (NULL);
		}
		new_line = (t_c_dot *)ft_calloc(linelen[1], sizeof(t_c_dot));
		cnt_x = 0;
		while(cnt_x < linelen[1])
		{
			my_set_c_dot(&new_line[cnt_x], cnt_x, ft_atoi(data_line[cnt_x]), cnt_z, 0x00FF0000);
			cnt_x++;
		}
		fdf->c_dots = fdf_conc_data(fdf->c_dots, new_line, linelen[1], cnt_z);
		cnt_z++;
		
		ft_free_multi_arr(data_line);
		linelen[0] = linelen[1];
		readline = get_next_line(fd);	
	}
	fdf->cnt_x = cnt_x;
	fdf->cnt_z = cnt_z;	
ft_printf("cnt_x:%d, cnt_z:%d\n", cnt_x, cnt_z);  //===========================
	my_init_mlx_win(mlx_arg, img, (cnt_x + 4) * 50, (cnt_z + 4) * 50);
}