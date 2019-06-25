/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:52:38 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		del(void *content, size_t size)
{
	(void)size;
	free(content);
}

static void		fun(t_list **head)
{
	t_list *save;

	while ((*head)->next != NULL)
	{
		save = (*head)->next;
		del((*head)->content, (*head)->content_size);
		free(*head);
		*head = NULL;
		(*head) = save;
	}
	del((*head)->content, (*head)->content_size);
	free(*head);
	*head = NULL;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list *list;
	t_list *head;

	list = NULL;
	if (!lst || !f)
		return (NULL);
	head = ft_lstnew(lst->content, lst->content_size);
	if (head == NULL)
		return (NULL);
	head = f(lst);
	list = head;
	while (lst->next != NULL)
	{
		lst = lst->next;
		list->next = ft_lstnew(lst->content, lst->content_size);
		if (list == NULL)
		{
			fun(&head);
			return (NULL);
		}
		list->next = f(lst);
		list = list->next;
	}
	return (head);
}
