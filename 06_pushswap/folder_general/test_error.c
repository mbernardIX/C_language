/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:48:50 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:48:51 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	max_and_min_int(t_link *link)
{
	t_stack	*stack_a;

	stack_a = link->start_a;
	while (stack_a)
	{
		if (stack_a->num > 2147483647)
			error();
		if (stack_a->num < -2147483648)
			error();
		stack_a = stack_a->next;
	}
}

void	duplicate(t_link *link)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	stack_a = link->start_a;
	while (stack_a)
	{
		tmp = stack_a->next;
		while (tmp)
			if (tmp->num == stack_a->num)
				error();
			else
				tmp = tmp->next;
		stack_a = stack_a->next;
	}
}

void	test_error(t_link *link)
{
	duplicate(link);
	max_and_min_int(link);
}
