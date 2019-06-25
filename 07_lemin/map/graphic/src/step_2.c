/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:57:16 by tmann             #+#    #+#             */
/*   Updated: 2019/04/20 18:35:48 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		intel_start_end(t_lem *po, t_lst *lst)
{
	if (po->check_start == 1)
	{
		lst->start = 1;
		po->check_start = 0;
	}
	else if (po->check_end == 1)
	{
		lst->end = 1;
		po->check_end = 0;
	}
}

int			intel_name_cor(char **param, int i, char *str, t_lst *lst)
{
	while (param[i] != NULL)
	{
		if (i == 0 && chek_num_al_l(param[i]) == 1)
		{
			if (ft_check_sim(str, '-') == 1)
				ft_error_ps();
			lst->name_s = ft_strdup(param[i]);
			i++;
		}
		else if (i == 1 && ft_check_str_numb(param[i]) == 1)
		{
			lst->corname_x = ft_swap_atoi(param[i]);
			i++;
		}
		else if (i == 2 && ft_check_str_numb(param[i]) == 1)
		{
			lst->corname_y = ft_swap_atoi(param[i]);
			i++;
		}
		else if (i >= 3)
			ft_error_ps();
		else
			ft_error_ps();
	}
	return (i);
}

void		check_name_cor(int i, t_lst *tmp)
{
	if (i > 3 || i < 3)
		ft_error_ps();
	check_double_cor(tmp);
	check_double_name(tmp);
}

void		check_line2(t_lem *po, t_lst *tmp, char *str)
{
	char	**param;
	t_lst	*lst;
	int		i;

	lst = tmp;
	param = ft_strsplit(str, ' ');
	while (lst->next != NULL)
		lst = lst->next;
	if (lst->is_first == 0)
	{
		lst->next = creat_list();
		lst = lst->next;
	}
	intel_start_end(po, lst);
	i = intel_name_cor(param, 0, str, lst);
	lst->is_first = 0;
	check_name_cor(i, tmp);
	ft_free_two_arr(param);
}
