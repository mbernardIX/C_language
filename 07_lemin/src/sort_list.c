/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:00 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst		*ft_put_on_start(t_lst *lst)
{
	t_lst *tmp;
	t_lst *back;
	t_lst *start;

	tmp = lst;
	back = NULL;
	start = NULL;
	while (tmp != NULL)
	{
		if (tmp->start == 1)
		{
			start = tmp;
			back->next = tmp->next;
			tmp->next = lst;
			break ;
		}
		back = tmp;
		tmp = tmp->next;
	}
	return (start);
}

t_lst		*ft_put_on_end(t_lst *lst)
{
	t_lst *tmp;
	t_lst *back;
	t_lst *start;

	tmp = lst;
	back = NULL;
	start = lst;
	while (lst->next != NULL)
		lst = lst->next;
	if (lst->end == 1)
		return (start);
	while (tmp != NULL)
	{
		if (tmp->end == 1)
		{
			back->next = tmp->next;
			lst->next = tmp;
			tmp->next = NULL;
			break ;
		}
		back = tmp;
		tmp = tmp->next;
	}
	return (start);
}

t_lst		*ft_sort_list(t_lst *lst)
{
	if (lst->start == 0)
		lst = ft_put_on_start(lst);
	lst = ft_put_on_end(lst);
	return (lst);
}
