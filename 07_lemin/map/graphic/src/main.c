/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:11:04 by tmann             #+#    #+#             */
/*   Updated: 2019/04/21 16:04:54 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(void)
{
	t_lem *po;
	t_lst *lst;

	po = NULL;
	lst = NULL;
	lst = creat_list();
	po = scan_param(po, lst);
	visualit(po, lst);
	free(lst->conn);
	free(lst->name_s);
	free(lst);
	free(po->command);
	free(po);
	return (0);
}
