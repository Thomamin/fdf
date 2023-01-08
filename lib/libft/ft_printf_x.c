/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:59:14 by dmin              #+#    #+#             */
/*   Updated: 2022/12/08 13:59:23 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(va_list vl, int is_up)
{
	unsigned int	num;
	int				len;

	num = va_arg(vl, unsigned int);
	len = ft_write_hex(num, 1, 1, is_up);
	return (len);
}
