#include <libft.h>
#include <mlx.h>
#include "fdf.h"

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

t_c_dot *ft_read_fdf(int fd, t_data *img)
{
	//int		readn;
	int		linelen[2];
	char	*readline;
	char	**data_line;
	t_c_dot	*fdf_data;
	int		cnt_x;
	int		cnt_z;

	linelen[0] = 0;
	// read input fdf file
	readline = get_next_line(fd);
	cnt_z = 0;
	while (readline != NULL)
	{	
		ft_printf("readline: %s", readline);
		data_line = ft_split(readline, ' ');
		linelen[1] = ft_get_fdf_line_len(data_line);
		if(linelen[0] != linelen[1] && linelen[0] != 0)
		{
			ft_printf("Error: fdf input widths different");
			return (NULL);
		}
		//create c_dot[data line length + 1]
		fdf_data = (t_c_dot *)ft_calloc(linelen[1], sizeof(t_c_dot));
		//convert char values to int 
		cnt_x = 0;
		while(cnt_x < linelen[1])
		{
			//assign values from datum to each c_dot[i]
			fdf_data[cnt_x].cx = cnt_x;
			fdf_data[cnt_x].cz = cnt_z;
			fdf_data[cnt_x].cy = ft_atoi(data_line[cnt_x]);
			cnt_x++;
		}
		// increase z value to next line
		cnt_z++;

		free(readline);
		ft_free_multi_arr(data_line);
		linelen[0] = linelen[1];
		readline = get_next_line(fd);	
	}

	(void) img;

	fdf_data = NULL;
	return (fdf_data);
}