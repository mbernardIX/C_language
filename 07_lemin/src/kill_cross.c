/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_cross.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:31 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		check_kill_cross(t_lst *lst, int j, int i)
{
	while (lst->par[i]->sizeconn > j)
	{
		while (lst->par[i]->conn[j] == NULL
			&& lst->par[i]->sizeconn > j)
			j++;
		if (lst->par[i]->sizeconn > j)
		{
			if (ft_strcmp(lst->name_s,
				lst->par[i]->conn[j]->name_s) == 0)
			{
				if (check_par(lst->par[i], 0, 0) == 0)
				{
					if (lst->alone == 1)
						break ;
					del_brother(lst->par[i]->conn[j],
					lst->par[i]->name_s);
					lst->par[i]->conn[j] = NULL;
				}
			}
		}
		j++;
	}
}

void			kill_cross(t_lst *lst)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (lst->sizepar >= 2 && lst->start == 0)
	{
		while (i < lst->sizepar)
		{
			if (lst->par[i]->sizeoutput >= 2 && lst->par[i]->start == 0)
				check_kill_cross(lst, j, i);
			j = 0;
			i++;
		}
	}
}
