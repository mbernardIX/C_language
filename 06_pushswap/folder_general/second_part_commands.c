/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:48:36 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:48:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	commands_ra(t_link *link)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	stack_a = link->start_a;
	if (stack_a)
	{
		tmp = stack_a->next;
		if (tmp)
		{
			tmp->prev = NULL;
			link->start_a = tmp;
			tmp = link->end_a;
			tmp->next = stack_a;
			stack_a->prev = tmp;
			stack_a->next = NULL;
			link->end_a = stack_a;
		}
	}
}

void	commands_rb(t_link *link)
{
	t_stack *stack_b;
	t_stack *tmp;

	stack_b = link->start_b;
	if (stack_b)
	{
		tmp = stack_b->next;
		if (tmp)
		{
			tmp->prev = NULL;
			link->start_b = tmp;
			tmp = link->end_b;
			tmp->next = stack_b;
			stack_b->prev = tmp;
			stack_b->next = NULL;
			link->end_b = stack_b;
		}
	}
}

void	commands_rr(t_link *link)
{
	commands_ra(link);
	commands_rb(link);
}
