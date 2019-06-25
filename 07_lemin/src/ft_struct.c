/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:37:28 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_struct_zero(t_lem *po)
{
	po->num_ants = 0;
	po->line = 0;
	po->check_start = 0;
	po->check_end = 0;
	po->command = NULL;
	po->val_end = 0;
	po->val_start = 0;
	po->min_way = 2147483647;
	po->bfs_count = 0;
	po->val_start = 0;
	po->size_con_end = 0;
	po->ways = NULL;
	po->here = NULL;
	po->run_num_ants = 0;
	po->count_way = 0;
}

void		ft_lst_zero(t_lst *lst)
{
	lst->name_s = NULL;
	lst->corname_x = -1;
	lst->corname_y = -1;
	lst->ant = 0;
	lst->conn = NULL;
	lst->start = 0;
	lst->end = 0;
	lst->next = NULL;
	lst->parent = NULL;
	lst->sizeconn = 0;
	lst->is_first = 0;
	lst->visited = 0;
	lst->green = 0;
	lst->sizepar = 0;
	lst->par = NULL;
	lst->go = NULL;
	lst->bfs_lvl = -1;
	lst->output = NULL;
	lst->sizeoutput = 0;
	lst->quick = NULL;
	lst->dead_end = 0;
	lst->alone = 0;
	lst->len_way = -1;
	lst->i = -1;
	lst->is_linked_with_start = 0;
}

t_lem		*sort_way(t_lem *po)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while ((po->count_way - 1) > i)
	{
		if (po->ways[i]->len_way > po->ways[i + 1]->len_way)
		{
			tmp = po->ways[i];
			po->ways[i] = po->ways[i + 1];
			po->ways[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (po);
}

void		ft_final(void)
{
	exit(0);
}
