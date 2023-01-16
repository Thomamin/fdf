/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fdf_sub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:41:39 by dmin              #+#    #+#             */
/*   Updated: 2023/01/16 11:41:43 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "fdf.h"

t_c_dot	*my_set_c_dot(t_c_dot *c_dot, double x, double y, double z)
{
	c_dot->cx = x;
	c_dot->cy = y;
	c_dot->cz = z;
	c_dot->color = 0x0000ff00;
	return (c_dot);
}
