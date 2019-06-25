/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:14:52 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/09 17:32:28 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*now;

	if (!lst || !f)
		return (0);
	begin = f(lst);
	now = begin;
	lst = lst->next;
	while (lst)
	{
		now->next = f(lst);
		lst = lst->next;
		now = now->next;
	}
	return (begin);
}
