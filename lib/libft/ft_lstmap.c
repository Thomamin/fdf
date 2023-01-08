/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:17:12 by dmin              #+#    #+#             */
/*   Updated: 2022/11/11 14:17:15 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_lst;

	new_lst = NULL;
	if (!lst || !f || !del)
		return ((t_list *) NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&new_lst, del);
			return ((t_list *) NULL);
		}
		ft_lstadd_back(&new_lst, new);
		lst = lst->next;
	}
	return (new_lst);
}

/*
#include	<stdio.h>
void   check_leak(void)
{
		system("leaks a.out");
}
int	main (void)
{
	t_list *node;
	t_list *lst;

	atexit(check_leak);
	lst = NULL;

	ft_lstadd_front(&lst, ft_lstnew(ft_strdup("I'm 1st content")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("I'm 2nd content")));
	//ft_lstiter(lst, &);
	printf("list size: %d\n", ft_lstsize(lst));
	node = lst;
	while (node)
	{
		printf("cont: %s\n", node->content);
		node = node->next;
	}
	node = ft_lstlast(lst);
	printf("Last node cont: %s\n", node->content);
	ft_lstclear(&lst, &free);
	printf("list size: %d\n", ft_lstsize(lst));
}
*/