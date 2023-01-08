/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:02:10 by dmin              #+#    #+#             */
/*   Updated: 2022/12/08 13:02:26 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_write_hex(unsigned long long ll_in, int p_dgt, int cnt_dgt, int is_cap)
{
	char				*hex;
	unsigned long long	ll_next;

	if (is_cap)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	ll_next = ll_in / 16;
	if (ll_next > 0)
		cnt_dgt = ft_write_hex(ll_next, p_dgt, cnt_dgt + 1, is_cap);
	else
	{
		while (cnt_dgt < p_dgt)
		{
			write(1, "0", 1);
			cnt_dgt++;
		}
	}
	write(1, &hex[ll_in % 16], 1);
	return (cnt_dgt);
}
