/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 12:40:49 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/22 18:21:52 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleanup(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		ft_memdel((void**)&lst);
		lst = temp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*n;
	t_list	*new_list;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = f(lst);
	new_list = ft_lstnew(temp->content, temp->content_size);
	if (new_list == NULL)
		return (NULL);
	n = new_list;
	while (lst->next)
	{
		lst = lst->next;
		temp = f(lst);
		n->next = ft_lstnew(temp->content, temp->content_size);
		if (n->next == NULL)
		{
			cleanup(new_list);
			return (NULL);
		}
		n = n->next;
	}
	return (new_list);
}
