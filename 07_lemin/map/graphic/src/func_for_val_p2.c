/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_val_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:32:16 by tmann             #+#    #+#             */
/*   Updated: 2019/04/20 16:38:17 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_double_name(t_lst *lst)
{
	t_lst *l1;
	t_lst *l2;

	l1 = lst;
	if (lst->next != NULL)
		l2 = lst->next;
	else
		return ;
	while (l1 != NULL)
	{
		while (l2 != NULL)
		{
			if (ft_strcmp(l1->name_s, l2->name_s) == 0)
				ft_error_ps();
			l2 = l2->next;
		}
		l1 = l1->next;
		if (l1->next != NULL)
			l2 = l1->next;
		else
			return ;
	}
}

void		check_double_cor(t_lst *lst)
{
	t_lst *l1;
	t_lst *l2;

	l1 = lst;
	if (lst->next != NULL)
		l2 = lst->next;
	else
		return ;
	while (l1 != NULL)
	{
		while (l2 != NULL)
		{
			if (l1->corname_x == l2->corname_x &&
				l1->corname_y == l2->corname_y)
				ft_error_ps();
			l2 = l2->next;
		}
		l1 = l1->next;
		if (l1->next != NULL)
			l2 = l1->next;
		else
			return ;
	}
}
