#include <libft.h>
#include <mlx.h>
#include "fdf.h"

t_c_dot *my_set_c_dot(t_c_dot *c_dot, double x, double y, double z, unsigned int color)
{
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
	return (len);
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

t_c_dot *fdf_con_d(t_c_dot *mem1, t_c_dot *mem2, size_t linelen, size_t lines)
{
	size_t line_data_size;
	t_c_dot *ret;

	line_data_size = linelen * sizeof(t_c_dot);
	ret = (t_c_dot *)ft_calloc(lines + 1, line_data_size);
	if (!ret)
		return (ft_err_mng(35, "mem alloc fail", mem1, mem2));
	if(mem1 != NULL)
		ft_memcpy(ret, mem1, line_data_size * lines);
	ft_memcpy(ret + linelen * lines, mem2, line_data_size);
	if(mem1)
		free(mem1);
	free(mem2);
	return(ret);
}

t_fdf *my_set_vals(t_fdf *fdf, int linelen, char *readline, char **dataline)
{
	t_c_dot	*new_line;		// data_line을 3차원 좌표로 변환한 좌표 구조체 배열 

	new_line = (t_c_dot *)ft_calloc(linelen, sizeof(t_c_dot));
	if(!new_line)
		return (ft_err_mng(32, "mem alloc fail", readline, new_line));
	fdf->cnt_x = 0;
	while(fdf->cnt_x < linelen)
	{
		my_set_c_dot(&new_line[fdf->cnt_x], fdf->cnt_x, \
		ft_atoi(dataline[fdf->cnt_x]), fdf->cnt_z, 0x00FF0000); //can add color option read 
		fdf->cnt_x++;
	}
	fdf->c_dots = fdf_con_d(fdf->c_dots, new_line, linelen, fdf->cnt_z);
	if(!fdf->c_dots)
		return (NULL);
	ft_free_multi_arr(dataline);
	free(readline);
	return (fdf);
}

t_c_dot *ft_read_fdf(t_fdf *fdf, int fd)
{
	int		linelen[2];
	char	*readline;      // gnl로 읽은 문자열
	char	**data_line;	// readline을 split으로 나눈 문자열 배열
	
	if (fd < 0)
		return (ft_err_mng(11, "Can't open file", NULL, NULL));
	linelen[0] = 0;
	readline = get_next_line(fd);
	fdf->cnt_z = 0;
	while (readline != NULL)
	{	
		data_line = ft_split(readline, ' ');
		if(!data_line)
			return (ft_err_mng(31, "split failed", readline, NULL));
		linelen[1] = ft_get_fdf_line_len(data_line);
		if(linelen[0] != linelen[1] && fdf->cnt_z > 0)
		{
			ft_free_multi_arr(data_line);
			return (ft_err_mng(12, "FDF input error", readline, fdf->c_dots));
		}
		fdf = my_set_vals(fdf, linelen[1], readline, data_line);
		fdf->cnt_z++;
		linelen[0] = linelen[1];
		readline = get_next_line(fd);
	}
	return (fdf->c_dots);
}