/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:35:53 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_conn(t_lst *lst, t_lst *head)
{
	if (head->conn == NULL)
	{
		head->conn = (t_lst**)malloc(sizeof(t_lst *));
		head->conn[0] = NULL;
	}
	if (head->conn[0] == NULL)
	{
		head->conn[0] = (t_lst*)malloc(sizeof(t_lst));
		head->sizeconn++;
		head->conn[0] = lst;
	}
	else
	{
		head->sizeconn++;
		re_write(head);
		head->conn[head->sizeconn - 1] = lst;
	}
}

void		look_val_name(t_lst *lst, t_lst *head)
{
	if (lst == NULL)
		ft_error_ps();
	if (head == NULL)
		ft_error_ps();
}

void		check_line3(t_lem *po, t_lst *lst, char *str, char **arr)
{
	t_lst	*head;

	head = lst;
	if (count_otr_len(str) != 1)
		ft_error_ps();
	arr = ft_strsplit(str, '-');
	if (arr == NULL || arr[0] == NULL || arr[1] == NULL
		|| arr[0][0] == '\0' || count_2d_len(arr) > 2)
		ft_error_ps();
	if (ft_check_sim(str, '-') == 1)
	{
		while (lst != NULL && ft_strcmp(lst->name_s, arr[0]) != 0)
			lst = lst->next;
		while (head != NULL && ft_strcmp(head->name_s, arr[1]) != 0)
			head = head->next;
		look_val_name(lst, head);
		check_conn(lst, head);
		check_conn(head, lst);
		if (po->line > 2)
			po->line--;
	}
	else
		ft_error_ps();
	check_double_line_conn(lst);
	ft_free_two_arr(arr);
}
