/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:45:46 by dmin              #+#    #+#             */
/*   Updated: 2022/11/14 17:45:49 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>

size_t	ft_strlen(const char *str);
char	*ft_uitoa(int n, int is_unsigned);
int		ft_write_hex(unsigned long long ll_in, int p_d, int cnt_d, int is_cap);
int		ft_printf_c(va_list vl);
int		ft_printf_s(va_list vl);
int		ft_printf_p(va_list vl);
int		ft_printf_d(va_list vl);
int		ft_printf_u(va_list vl);
int		ft_printf_x(va_list vl, int is_up);
int		ft_printf(const char *in_str, ...);
#endif