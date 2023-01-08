/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:09:47 by dmin              #+#    #+#             */
/*   Updated: 2022/11/07 11:10:00 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;
	size_t	indx;

	len = ft_strlen(s);
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		ret = (void *) NULL;
	else
	{
		indx = 0;
		while (*(s + indx))
		{
			*(ret + indx) = f(indx, *(s + indx));
			indx++;
		}
		*(ret + indx) = '\0';
	}
	return (ret);
}
