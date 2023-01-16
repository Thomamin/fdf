/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_mng.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:41:03 by dmin              #+#    #+#             */
/*   Updated: 2023/01/16 11:41:07 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
