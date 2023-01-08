/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:58:06 by dmin              #+#    #+#             */
/*   Updated: 2022/12/08 13:58:21 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printf_p(va_list vl)
{
	unsigned long long	addr;
	int					len;

	addr = 0;
	addr = (unsigned long long)va_arg(vl, void *);
	if (!addr)
		addr = 0;
	write(1, "0x", 2);
	len = 2;
	len += ft_write_hex(addr, 1, 1, 0);
	return (len);
}
