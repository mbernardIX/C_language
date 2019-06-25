/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:34 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			help_add_queue(t_lst *lst, int i)
{
	lst->conn[i]->visited = 1;
	lst->conn[i]->parent = lst;
	lst->conn[i]->bfs_lvl += lst->bfs_lvl + 2;
	if (lst->conn[i]->sizeconn == 1 &&
		lst->conn[i]->conn[0]->bfs_lvl < lst->conn[i]->bfs_lvl)
		del_dead_end(lst->conn[i], 0);
}

static t_queue		*for_norm(t_queue *qu, int i, t_lst *lst)
{
	qu = qu->next;
	qu->name = lst->conn[i];
	return (qu);
}

static t_queue		*check_queue(t_queue *qu, t_lst *lst, int i)
{
	if (lst->conn[i] != NULL && lst->conn[i]->visited == 0)
	{
		if (lst->conn[i]->end == 1)
		{
			if (i < lst->sizeconn)
				i++;
		}
		else if (qu->name == NULL)
		{
			qu->name = lst->conn[i];
			help_add_queue(lst, i);
		}
		else
		{
			qu->next = creat_queue();
			qu = for_norm(qu, i, lst);
			help_add_queue(lst, i);
		}
		if (lst->conn[i + 1] != NULL)
		{
			qu->next = creat_queue();
			qu = qu->next;
		}
	}
	return (qu);
}

t_queue				*ft_add_first_in_queue(t_queue *head,
	t_queue *qu, t_lst *lst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lst->sizeconn)
	{
		qu = check_queue(qu, lst, i);
		i++;
	}
	if (lst->is_first == 0)
		head = ft_delete_out_queue(head);
	return (head);
}
