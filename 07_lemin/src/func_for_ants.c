/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:37:25 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem		*creat_arr_ways(t_lem *po, t_lst *lst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	po->ways = (t_lst **)malloc(sizeof(t_lst *) * po->count_way + 1);
	while (lst->sizeconn > i)
	{
		if (lst->conn[i] == NULL && lst->sizeconn > i)
			i++;
		if (lst->conn[i]->go != NULL)
		{
			lst->conn[i]->is_linked_with_start = 1;
			po->ways[j] = lst->conn[i];
			j++;
		}
		i++;
	}
	po->ways[j] = NULL;
	return (po);
}

t_lem		*create_arr_ants(t_lem *po)
{
	int i;

	i = 0;
	po->here = (t_lst**)malloc(sizeof(t_lst*) * po->num_ants + 1);
	while (po->num_ants >= i)
	{
		po->here[i] = NULL;
		i++;
	}
	return (po);
}

void		count_ants_for_ways(t_lem *po, int num_ants)
{
	int i;

	i = 0;
	while (num_ants != 0)
	{
		if (po->ways[i + 1] != NULL)
		{
			if (po->ways[i]->len_way <= po->ways[i + 1]->len_way)
			{
				po->ways[i]->green++;
				po->ways[i]->len_way++;
				num_ants--;
				i--;
			}
			i++;
		}
		else if (po->ways[i + 1] == NULL)
		{
			po->ways[i]->green++;
			po->ways[i]->len_way++;
			num_ants--;
			i = 0;
		}
	}
}

t_lem		*creat_way_for_ants(t_lst *lst, t_lem *po)
{
	int	count_way;
	int i;

	count_way = 0;
	i = 0;
	while (lst->sizeconn > i)
	{
		if (lst->conn[i]->go != NULL)
			count_way++;
		i++;
	}
	po->count_way = count_way;
	po = creat_arr_ways(po, lst);
	po = sort_way(po);
	return (po);
}

int			is_all_ants_in_end(t_lem *po)
{
	int i;

	i = 0;
	while (i < po->num_ants)
	{
		if (po->here[i] != NULL)
			return (1);
		i++;
	}
	return (0);
}
