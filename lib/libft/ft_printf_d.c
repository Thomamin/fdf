/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:58:37 by dmin              #+#    #+#             */
/*   Updated: 2022/12/08 13:58:41 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

int	ft_printf_d(va_list vl)
{
	int				num;
	int				len;
	char			*str_num;
	int				is_unsigned;

	is_unsigned = 0;
	num = va_arg(vl, int);
	str_num = ft_uitoa(num, is_unsigned);
	len = ft_strlen(str_num);
	write(1, str_num, len);
	free(str_num);
	return (len);
}
