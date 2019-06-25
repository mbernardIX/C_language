/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_lem.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:38 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			ft_bfs(t_lst *lst, t_lem *po)
{
	t_lst		*tmp;
	t_queue		*qu;

	tmp = lst;
	qu = creat_queue();
	if (lst->start == 1 && lst->conn == NULL)
		ft_error_ps();
	lst->visited = 1;
	lst->is_first = 1;
	lst->bfs_lvl = 0;
	qu = ft_add_in_queue(qu, tmp);
	while (qu != NULL)
	{
		tmp = qu->name;
		if (tmp == NULL)
			break ;
		qu = ft_add_in_queue(qu, tmp);
	}
	tmp = lst;
	while (tmp->end != 1)
		tmp = tmp->next;
	tmp->bfs_lvl = 2147483647;
	run_ways_from_end(tmp, po, -1, 0);
}

static void		help_from_end(t_lst *tmp, int size_way)
{
	tmp->len_way = size_way + 1;
	tmp->parent->go = tmp;
}

void			run_ways_from_end(t_lst *lst, t_lem *po, int i, int size_way)
{
	t_lst	*tmp;

	while (lst->conn != NULL && lst->sizeconn > ++i)
	{
		tmp = lst->conn[i];
		tmp->len_way++;
		lst->conn[i]->go = lst;
		if (tmp->parent != NULL)
		{
			while (tmp != NULL && tmp->start != 1)
			{
				if (tmp->visited == 1)
					tmp->visited = 0;
				help_from_end(tmp, size_way);
				tmp = tmp->parent;
				size_way++;
			}
			if (po->min_way > size_way)
			{
				po->min_way = size_way;
				creat_quick_way(tmp);
			}
		}
		size_way = 0;
	}
}
