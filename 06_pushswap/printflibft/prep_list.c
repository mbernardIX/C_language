/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 13:09:28 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/09 20:07:15 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	prep_t_print(t_print *list)
{
	list->type = '0';
	list->flag = 1;
	list->width = 0;
	list->accur = -1;
	list->mod = 0;
	list->space_one = 0;
	list->is = 0;
	list->p_or_n = ' ';
	list->nulls = 0;
	list->space_end = 0;
	list->len_bef = 0;
	list->point = 0;
	list->len_after = 0;
}
