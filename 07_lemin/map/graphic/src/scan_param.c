/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 16:56:43 by tmann             #+#    #+#             */
/*   Updated: 2019/04/21 16:04:27 by dmorar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		readparam(char *line, t_lem *po, t_lst *lst)
{
	t_lst *head;

	head = lst;
	while (get_next_line(0, &line) > 0)
	{
		if (*line == '\0' && lst->name_s == NULL)
			ft_error_ps();
		if (*line == '\0')
			break ;
		if (po->line > 0)
			po->command = ft_strjoin_free(po->command, "\n", 1, 0);
		po->command = ft_strjoin_free(po->command, line, 1, 0);
		po->line++;
		val_param(line, po, lst, head);
	}
	check_start_end(head, 0, 0);
	if (po->line < 2)
		ft_error_ps();
	if (po->num_ants <= 0)
		ft_error_ps();
	ft_printf("%s\n\n", po->command);
	lst = head;
}

t_lem		*scan_param(t_lem *po, t_lst *lst)
{
	t_lst *head;

	head = lst;
	po = (t_lem*)malloc(sizeof(t_lem));
	ft_struct_zero(po);
	po->command = ft_strdup("");
	head->is_first = 1;
	readparam(NULL, po, head);
	return (po);
}
