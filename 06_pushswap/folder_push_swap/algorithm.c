/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:50:00 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:50:05 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*result_of_prepare(t_link *link)
{
	t_stack	*stack_a;
	t_stack	*tmp;
	int		i;

	i = 0;
	stack_a = link->start_a;
	while (stack_a)
	{
		tmp = stack_a->next;
		if (tmp)
		{
			if (tmp->num < stack_a->num && (link->max != stack_a->num ||
						tmp->next == NULL))
				i++;
		}
		else
			break ;
		stack_a = stack_a->next;
	}
	if (i == 0)
		return ("OK");
	else
		return ("KO");
}

void	end(t_link *link, long i)
{
	t_stack	*tmp;

	tmp = link->start_a;
	while (tmp)
	{
		if (tmp->num == link->min)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (2 * i > link->len_a)
		i = i - link->len_a - 1;
	while (i > 0 && i-- > 0)
	{
		commands_ra(link);
		ft_putstr("ra\n");
		output_elem(link);
	}
	while (i < 0 && i++ < 0)
	{
		commands_rra(link);
		ft_putstr("rra\n");
		output_elem(link);
	}
}

void	algorithm_part_two(t_link *link, t_stack *choose)
{
	while (choose->oper_b < 0 && choose->oper_a < 0)
	{
		choose->oper_a++;
		choose->oper_b++;
		commands_rrr(link);
		ft_putstr("rrr\n");
		output_elem(link);
	}
	while (choose->oper_b < 0)
	{
		choose->oper_b++;
		commands_rrb(link);
		ft_putstr("rrb\n");
		output_elem(link);
	}
	while (choose->oper_a < 0)
	{
		choose->oper_a++;
		commands_rra(link);
		ft_putstr("rra\n");
		output_elem(link);
	}
	commands_pa(link);
	ft_putstr("pa\n");
}

void	algorithm(t_link *link, t_stack *choose)
{
	while (choose->oper_b > 0 && choose->oper_a > 0)
	{
		choose->oper_a--;
		choose->oper_b--;
		commands_rr(link);
		ft_putstr("rr\n");
		output_elem(link);
	}
	while (choose->oper_b > 0)
	{
		choose->oper_b--;
		commands_rb(link);
		ft_putstr("rb\n");
		output_elem(link);
	}
	while (choose->oper_a > 0)
	{
		choose->oper_a--;
		commands_ra(link);
		ft_putstr("ra\n");
		output_elem(link);
	}
	algorithm_part_two(link, choose);
}
