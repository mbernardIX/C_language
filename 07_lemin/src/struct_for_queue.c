/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_for_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:35:48 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_zero_queue(t_queue *qu)
{
	qu->name = NULL;
	qu->next = NULL;
}

void		*creat_queue(void)
{
	t_queue	*qu;

	qu = (t_queue*)malloc(sizeof(t_queue));
	qu->name = (t_lst*)malloc(sizeof(t_lst));
	ft_zero_queue(qu);
	return (qu);
}
