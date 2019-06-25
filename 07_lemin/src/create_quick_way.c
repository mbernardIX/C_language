/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_quick_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:37:39 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lst		*for_func_quick(int i, t_lst *tmp)
{
	tmp->quick = tmp->conn[i];
	tmp->quick->visited = 1;
	tmp = tmp->quick;
	return (tmp);
}

t_lst		*check_quick(int i, t_lst *tmp)
{
	while (tmp->sizeconn > i)
	{
		if (tmp->conn[i]->parent != NULL && tmp->conn[i]->visited == 0)
		{
			if (tmp->start == 1)
			{
				tmp = for_func_quick(i, tmp);
				break ;
			}
			else if (ft_strcmp(tmp->conn[i]->name_s,
				tmp->parent->name_s) != 0)
			{
				tmp = for_func_quick(i, tmp);
				break ;
			}
		}
		else if (tmp->conn[i]->end == 1)
		{
			tmp = for_func_quick(i, tmp);
			break ;
		}
		i++;
	}
	return (tmp);
}

void		creat_quick_way(t_lst *lst)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp != NULL && tmp->end != 1)
	{
		tmp = check_quick(i, tmp);
		i = 0;
	}
}
