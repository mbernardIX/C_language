/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:27 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_visited(t_lst *lst)
{
	while (lst)
	{
		lst->visited = 0;
		lst = lst->next;
	}
}

void		func_kill_cross(t_lst *lst)
{
	while (lst->end != 1)
	{
		if (lst->start == 1)
			lst = lst->next;
		if (lst->end == 0)
			kill_cross(lst);
		lst = lst->next;
	}
}

void		c_par_out(t_lst *lst, t_lem *po)
{
	while (lst)
	{
		lst->visited = 0;
		if (lst->start == 1)
		{
			po->size_con_start = lst->sizeconn;
			lst = lst->next;
		}
		if (lst->end == 1)
			po->size_con_end = lst->sizeconn;
		create_par(lst);
		create_output(lst);
		lst = lst->next;
	}
}

int			main(void)
{
	t_lem	*po;
	t_lst	*lst;

	po = NULL;
	lst = creat_list();
	po = scan_param(po, lst);
	lst = ft_sort_list(lst);
	ft_bfs(lst, po);
	start_end(lst, po);
	c_par_out(lst, po);
	func_kill_cross(lst);
	free_visited(lst);
	ft_bfs(lst, po);
	po = creat_way_for_ants(lst, po);
	po = create_arr_ants(po);
	count_ants_for_ways(po, po->num_ants);
	create_ants_here(po, 0, 0, 0);
	ft_final();
	return (0);
}
