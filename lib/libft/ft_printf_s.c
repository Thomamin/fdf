/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:36:38 by dmin              #+#    #+#             */
/*   Updated: 2022/12/08 13:36:42 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_printf_s(va_list vl)
{
	char	*str;
	int		len;

	str = va_arg(vl, char *);
	if (!str)
	{
		str = "(null)";
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
