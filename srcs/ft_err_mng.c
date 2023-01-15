#include <libft.h>
#include "fdf.h"

void	*ft_err_mng(int err_code, char *err_msg, void *mem1, void *mem2)
{
	if (err_code != 0)
		ft_printf("Error(%d): %s\n", err_code, err_msg);
	if (mem1 != NULL)
		free(mem1);
	if (mem2 != NULL)
		free(mem2);
	return (NULL);
}
