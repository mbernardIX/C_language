/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_val.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:37:17 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		check_start_end(t_lst *lst, int cs, int ce)
{
	t_lst *l1;

	l1 = lst;
	while (l1 != NULL)
	{
		if (l1->start == 1)
		{
			if (l1->end == 1)
				ft_error_ps();
			cs++;
		}
		if (l1->end == 1)
		{
			if (l1->start == 1)
				ft_error_ps();
			ce++;
		}
		l1 = l1->next;
	}
	if (cs > 1 || ce > 1)
		ft_error_ps();
	else if (cs == 0 || ce == 0)
		ft_error_ps();
}

void		check_double_line_conn(t_lst *lst)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (i < lst->sizeconn)
	{
		while (j < lst->sizeconn)
		{
			if (lst->conn[i] == lst->conn[j])
				ft_error_ps();
			j++;
		}
		i++;
		j = i + 1;
	}
}

int			count_2d_len(char **arr)
{
	int i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

int			count_otr_len(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	return (count);
}
