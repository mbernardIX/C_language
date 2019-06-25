/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:48:28 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:48:30 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error(void)
{
	ft_putstr("Error\n");
	exit(0);
}

void	output_elem_accur(t_stack *list)
{
	t_stack	*tmp;

	while (list)
	{
		tmp = list->prev;
		ft_putstr("\nlist->prev   ");
		if (tmp)
			ft_putnbr(tmp->num);
		else
			ft_putstr("N");
		ft_printf(" | list->num    %ld", list->num);
		tmp = list->next;
		ft_putstr(" | list->next   ");
		if (tmp)
			ft_putnbr(tmp->num);
		else
			ft_putstr("N");
		ft_printf(" | list->oper_a %ld", list->oper_a);
		ft_printf(" | list->oper_b %ld", list->oper_b);
		list = list->next;
	}
}

void	output_elem(t_link *link)
{
	t_stack	*tmp;

	if (link->mod_v)
	{
		tmp = link->start_a;
		ft_printf("Stack A (go with top) =");
		while (tmp)
		{
			ft_printf(" %ld", tmp->num);
			tmp = tmp->next;
		}
		if (link->mod_l)
			output_elem_accur(link->start_a);
		ft_putchar('\n');
		tmp = link->start_b;
		ft_printf("Stack B (go with top) =");
		while (tmp)
		{
			ft_printf(" %ld", tmp->num);
			tmp = tmp->next;
		}
		if (link->mod_l)
			output_elem_accur(link->start_b);
		ft_putchar('\n');
	}
}
