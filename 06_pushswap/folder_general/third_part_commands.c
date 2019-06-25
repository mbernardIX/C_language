/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_part_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:48:57 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:48:58 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	commands_rra(t_link *link)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	stack_a = link->start_a;
	if (stack_a)
	{
		tmp = link->end_a;
		if (tmp)
		{
			tmp->next = stack_a;
			stack_a->prev = tmp;
			stack_a = tmp->prev;
			stack_a->next = NULL;
			tmp->prev = NULL;
			link->start_a = tmp;
			link->end_a = stack_a;
		}
	}
}

void	commands_rrb(t_link *link)
{
	t_stack *stack_b;
	t_stack *tmp;

	stack_b = link->start_b;
	if (stack_b)
	{
		tmp = link->end_b;
		if (tmp)
		{
			tmp->next = stack_b;
			stack_b->prev = tmp;
			stack_b = tmp->prev;
			stack_b->next = NULL;
			tmp->prev = NULL;
			link->start_b = tmp;
			link->end_b = stack_b;
		}
	}
}

void	commands_rrr(t_link *link)
{
	commands_rra(link);
	commands_rrb(link);
}
