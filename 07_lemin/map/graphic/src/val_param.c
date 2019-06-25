/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:47:26 by tmann             #+#    #+#             */
/*   Updated: 2019/04/20 20:29:30 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		step_1(char *str, t_lem *po)
{
	if (po->line == 1 && ft_check_str_numb(str) == 1)
	{
		if (ft_check_str_numb(str) == 1)
			po->num_ants = ft_swap_atoi(str);
		else
			ft_error_ps();
	}
	else if (po->line == 1)
	{
		if (str[0] == '#' && str[1] != '#')
		{
			if (po->line > 0)
				po->line--;
			return ;
		}
		else if (po->line == 1)
			ft_error_ps();
	}
}

void		step_2(char *str, t_lem *po)
{
	if (ft_strcmp(str, "##start") == 0)
	{
		po->check_start = 1;
		if (po->line > 1)
			po->line--;
		return ;
	}
	else if (ft_strcmp(str, "##end") == 0)
	{
		po->check_end = 1;
		if (po->line > 1)
			po->line--;
		return ;
	}
	else if (po->line > 1)
		po->line--;
}

void		step_2_p2(char *str, t_lem *po, t_lst *lst, t_lst *head)
{
	if (str[0] == '#' && str[1] != '#')
	{
		if (po->line > 1)
			po->line--;
		return ;
	}
	if (str[0] == '#' && str[1] == '#')
		step_2(str, po);
	else if (ft_check_sim(str, ' ') == 1)
	{
		check_line2(po, lst, str);
		po->line--;
	}
	else if (ft_check_sim(str, '-') == 1)
	{
		lst = head;
		po->line++;
	}
	else
		ft_error_ps();
}

void		val_param(char *str, t_lem *po, t_lst *lst, t_lst *head)
{
	if (po->line == 1)
		step_1(str, po);
	if (po->line == 2)
		step_2_p2(str, po, lst, head);
	if (po->line == 3)
	{
		if (str[0] == '#' && str[1] != '#')
		{
			if (po->line > 2)
				po->line--;
			return ;
		}
		check_line3(po, lst, str, NULL);
	}
}
