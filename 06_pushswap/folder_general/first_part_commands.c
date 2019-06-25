/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:48:21 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:48:23 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	commands_sa(t_link *link)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	if (link->start_a != NULL)
	{
		stack_a = link->start_a;
		if (stack_a->next != NULL)
		{
			tmp = stack_a->next;
			stack_a->prev = tmp;
			stack_a->next = tmp->next;
			tmp->next = stack_a;
			tmp->prev = NULL;
			link->start_a = tmp;
			if (stack_a->next == NULL)
				link->end_a = stack_a;
			tmp = stack_a->next;
			if (tmp)
				tmp->prev = stack_a;
		}
	}
}

void	commands_sb(t_link *link)
{
	t_stack *stack_b;
	t_stack *tmp;

	if (link->start_b != NULL)
	{
		stack_b = link->start_b;
		if (stack_b->next != NULL)
		{
			tmp = stack_b->next;
			stack_b->prev = stack_b->next;
			stack_b->next = tmp->next;
			tmp->next = stack_b;
			tmp->prev = NULL;
			link->start_b = tmp;
			if (stack_b->next == NULL)
				link->end_b = stack_b;
			tmp = stack_b->next;
			if (tmp)
				tmp->prev = stack_b;
		}
	}
}

void	commands_ss(t_link *link)
{
	commands_sa(link);
	commands_sb(link);
}

void	commands_pa(t_link *link)
{
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_b = link->start_b;
	if (stack_b != NULL)
	{
		tmp = stack_b->next;
		if (tmp)
			tmp->prev = NULL;
		link->start_b = tmp;
		tmp = link->start_a;
		stack_b->next = tmp;
		if (tmp != NULL)
			tmp->prev = stack_b;
		link->start_a = stack_b;
		if (tmp == NULL)
			link->end_a = stack_b;
	}
}

void	commands_pb(t_link *link)
{
	t_stack *stack_a;
	t_stack *tmp;

	stack_a = link->start_a;
	if (stack_a != NULL)
	{
		tmp = stack_a->next;
		if (tmp)
			tmp->prev = NULL;
		link->start_a = tmp;
		tmp = link->start_b;
		stack_a->next = tmp;
		if (tmp != NULL)
			tmp->prev = stack_a;
		link->start_b = stack_a;
		if (tmp == NULL)
			link->end_b = stack_a;
	}
}
