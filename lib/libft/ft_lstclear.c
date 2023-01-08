/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:52:18 by dmin              #+#    #+#             */
/*   Updated: 2022/11/11 13:52:31 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*c_node;
	t_list	*last_node;

	if (lst && del)
	{
		c_node = (*lst);
		while (c_node != NULL)
		{
			last_node = c_node;
			c_node = c_node->next;
			ft_lstdelone(last_node, del);
		}
		*lst = NULL;
	}
	else
		return ((void) NULL);
}
