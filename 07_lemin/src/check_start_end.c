/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:55 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_s_e(t_lst *lst, t_lem *po)
{
	int i;

	i = 0;
	while (po->num_ants > i)
	{
		ft_printf("L%d-%s ", i + 1, lst->name_s);
		i++;
	}
	ft_printf("\n");
	exit(0);
}

void			start_end(t_lst *lst, t_lem *po)
{
	int i;

	i = 0;
	while (lst->sizeconn > i)
	{
		if (lst->conn[i]->end == 1)
			print_s_e(lst->conn[i], po);
		i++;
	}
}
