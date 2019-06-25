/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:23:50 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/09 17:30:01 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *begin;

	if (!lst || !f)
		return ;
	f(lst);
	begin = lst;
	lst = lst->next;
	while (lst)
	{
		f(lst);
		lst = lst->next;
	}
	lst = begin;
	return ;
}
