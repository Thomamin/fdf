/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:45:08 by dmin              #+#    #+#             */
/*   Updated: 2022/11/11 13:48:06 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*c_lst;

	if (lst && new)
	{
		if (*lst)
		{
			c_lst = ft_lstlast(*lst);
			c_lst->next = new;
		}
		else
			*lst = new;
	}
	else
		return ((void) NULL);
}
