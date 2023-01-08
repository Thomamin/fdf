/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmin <dmin@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:58:21 by dmin              #+#    #+#             */
/*   Updated: 2022/11/11 12:58:27 by dmin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return ((t_list *) NULL);
	lst->content = content;
	lst->next = (t_list *) NULL;
	return (lst);
}
/*
#include	<stdio.h>
int	main(void)
{
	char *str = "test string";
	t_list	*lst = ft_lstnew(str);
	printf("%s", lst->content);
}
*/