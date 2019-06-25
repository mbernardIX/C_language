/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:54:28 by tmann             #+#    #+#             */
/*   Updated: 2019/04/21 14:15:46 by tmann            ###   ########.fr       */
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
	lst->sizeconn = 0;
	lst->is_first = 0;
}

t_lst		*creat_list(void)
{
	t_lst *lst;

	lst = (t_lst*)malloc(sizeof(t_lst));
	ft_lst_zero(lst);
	return (lst);
}

void		re_write(t_lst *lst)
{
	t_lst	**new;
	int		i;

	i = 0;
	new = (t_lst**)malloc(sizeof(t_lst*) * (lst->sizeconn + 1));
	while (i < lst->sizeconn)
	{
		new[i] = (t_lst*)malloc(sizeof(t_lst));
		new[i] = lst->conn[i];
		i++;
	}
	new[i] = NULL;
	free(lst->conn);
	lst->conn = NULL;
	lst->conn = new;
}
