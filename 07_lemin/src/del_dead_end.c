/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_dead_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:37:34 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			check_dead_end(t_lst *lst, t_lst *lost, int i)
{
	while (lst->sizeconn > i)
	{
		while (lst->conn[i] == NULL && lst->sizeconn > i)
			i++;
		if (lst->sizeconn > i)
		{
			if (lst->sizeconn > i &&
				ft_strcmp(lst->conn[i]->name_s, lost->name_s) == 0)
				lst->conn[i]->dead_end = -1;
			i++;
		}
	}
}

void				add_param_for_dead_end(t_lst *lst)
{
	lst->conn[0] = NULL;
	lst->sizeconn--;
	lst->dead_end = -1;
}

void				del_dead_end(t_lst *lst, int check)
{
	t_lst	*tmp;
	t_lst	*lost;

	while (lst)
	{
		if (lst->sizeconn > 1)
		{
			if (check > 0)
				lst->sizeconn++;
			check_dead_end(lst, lost, 0);
			return ;
		}
		else if (lst->sizeconn == 1 && lst->conn[0]->bfs_lvl < lst->bfs_lvl)
		{
			tmp = lst->conn[0];
			lost = lst;
			add_param_for_dead_end(lst);
			lst = tmp;
			lst->sizeconn--;
			check++;
		}
		else
			return ;
	}
}
