/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:58:57 by dmin              #+#    #+#             */
/*   Updated: 2022/12/08 13:59:01 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

int	ft_printf_u(va_list vl)
{
	unsigned int	num;
	int				len;
	char			*str_num;
	int				is_unsigned;

	is_unsigned = 1;
	num = va_arg(vl, unsigned int);
	str_num = ft_uitoa(num, is_unsigned);
	len = ft_strlen(str_num);
	write(1, str_num, len);
	free(str_num);
	return (len);
}
