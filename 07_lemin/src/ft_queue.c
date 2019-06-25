/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:37:31 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_double_par(t_lst *p, t_lst *lst)
{
	int	i;

	i = 0;
	while (lst->sizepar > i)
	{
		if (p->par != NULL && p->par[i] != NULL)
		{
			if (ft_strcmp(lst->name_s, p->par[i]->name_s) == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

void		create_par(t_lst *lst)
{
	int i;

	i = 0;
	if (lst->start == 0)
	{
		while (lst->sizeconn > i)
		{
			while (lst->conn[i] == NULL && lst->sizeconn > i)
				i++;
			if (lst->sizeconn > i)
			{
				if (lst->conn[i]->bfs_lvl <= lst->bfs_lvl)
				{
					try_write_par(lst);
					lst->par[0] = lst->conn[i];
				}
			}
			i++;
		}
	}
}

void		create_output(t_lst *lst)
{
	int i;

	i = 0;
	while (lst->sizeconn > i)
	{
		while (lst->conn[i] == NULL && lst->sizeconn > i)
			i++;
		if (lst->sizeconn > i)
		{
			if (lst->conn[i]->bfs_lvl >= lst->bfs_lvl)
			{
				re_output(lst);
				lst->output[0] = lst->conn[i];
			}
		}
		i++;
	}
}

t_queue		*ft_add_in_queue(t_queue *qu, t_lst *lst)
{
	t_queue	*tmp;

	tmp = qu;
	if (tmp != NULL && tmp->next != NULL)
	{
		while (tmp != NULL && tmp->next != NULL)
		{
			tmp = tmp->next;
		}
	}
	qu = ft_add_first_in_queue(qu, tmp, lst);
	return (qu);
}

t_queue		*ft_delete_out_queue(t_queue *qu)
{
	t_queue	*tmp;

	tmp = qu;
	qu = qu->next;
	if (tmp->name == NULL)
		return (qu);
	tmp->next = NULL;
	free(tmp);
	return (qu);
}
