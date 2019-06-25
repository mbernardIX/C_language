/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:36:07 by dspider-         ###   ########.fr       */
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
