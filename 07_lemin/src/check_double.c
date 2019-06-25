/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:41 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_double_output(t_lst *p, t_lst *lst)
{
	int i;
	int ch;

	i = 0;
	ch = 0;
	while (lst->sizepar > i)
	{
		if (p->par != NULL && p->par[i] != NULL)
		{
			if (ft_strcmp(lst->name_s, lst->par[i]->name_s) == 0)
				ch++;
		}
		i++;
	}
	if (ch > 0)
	{
		if (lst->sizepar == 2)
			ch++;
	}
	if (lst->sizepar == 1)
		return (0);
	if (p->sizepar - ch > 0)
		return (1);
	else
		return (0);
}

int			check_double_op(t_lst *lst)
{
	int i;

	i = 0;
	while (lst->sizeoutput > i)
	{
		if (check_double_output(lst, lst->output[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int			check_par(t_lst *lst, int i, int check)
{
	while (lst->sizeoutput > i)
	{
		while (lst->output[i] == NULL && lst->sizeoutput > i)
			i++;
		if (lst->sizeoutput > i && lst->output[i]->end == 1)
		{
			i++;
			check++;
		}
		if (lst->output[i] != NULL && lst->sizeoutput > i)
		{
			if (check_par_dead_end(lst->output[i], lst, 0, 0) == 0)
			{
				check++;
				if (lst->sizeoutput <= i)
					return (1);
			}
		}
		i++;
	}
	if ((lst->sizeoutput - check) < 1)
		return (1);
	return (0);
}

void		del_brother(t_lst *lst, char *brother)
{
	int i;

	i = 0;
	while (lst->sizeconn > i)
	{
		while (lst->conn[i] == NULL && lst->sizeconn > i)
			i++;
		if (lst->sizeconn > i && ft_strcmp(lst->conn[i]->name_s, brother) == 0)
			lst->conn[i] = NULL;
		i++;
	}
}
