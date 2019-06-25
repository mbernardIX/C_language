/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:50:18 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:50:20 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	choose_the_best(t_link *link)
{
	t_stack	*tmp;
	t_stack	*choose;
	long	i;

	tmp = link->start_b;
	choose = tmp;
	i = tmp->oper_a + max(tmp->oper_b, -tmp->oper_b);
	tmp = tmp->next;
	while (tmp)
	{
		if (i > max(tmp->oper_a, -tmp->oper_a) + max(tmp->oper_b, -tmp->oper_b))
		{
			i = max(tmp->oper_a, -tmp->oper_a) + max(tmp->oper_b, -tmp->oper_b);
			choose = tmp;
		}
		tmp = tmp->next;
	}
	if (2 * choose->oper_a > link->len_a)
		choose->oper_a = choose->oper_a - link->len_a;
	algorithm(link, choose);
}

void	length_in_a(t_link *link)
{
	t_stack	*tmp;
	t_stack	*time;
	t_stack	*p;
	long	i;

	p = link->start_b;
	while (p)
	{
		i = 1;
		tmp = link->start_a;
		while (tmp && tmp->next)
		{
			time = tmp->next;
			if (tmp->num < p->num && p->num < time->num)
				break ;
			tmp = tmp->next;
			i++;
		}
		p->oper_a = i % link->len_a;
		p = p->next;
	}
}

void	length_in_b(t_link *link)
{
	t_stack	*tmp_start;
	t_stack	*tmp_end;
	long	i;

	tmp_start = link->start_b;
	tmp_end = link->end_b;
	if (tmp_start)
		tmp_start->oper_b = 0;
	tmp_start = tmp_start->next;
	i = 1;
	while (2 * i - 1 <= link->len_b)
	{
		tmp_end->oper_b = -i;
		tmp_start->oper_b = i;
		tmp_start = tmp_start->next;
		tmp_end = tmp_end->prev;
		i++;
	}
}

void	sort_start_position(t_link *link)
{
	t_stack	*tmp;
	t_stack	*second;

	tmp = link->start_a;
	second = tmp->next;
	if (second == NULL)
		return ;
	if (second->next == NULL)
		return ;
	if (tmp->num == link->min && second->num == link->max)
	{
		commands_sa(link);
		ft_putstr("sa\n");
	}
	else if (tmp->num == link->max && second->num != link->min)
	{
		commands_sa(link);
		ft_putstr("sa\n");
	}
	else if (tmp->num != link->max && second->num == link->min)
	{
		commands_sa(link);
		ft_putstr("sa\n");
	}
	output_elem(link);
}

void	first_work(t_link *link, t_stack *tmp)
{
	while (link->len_a >= 3 && ft_strcmp("KO", result_of_prepare(link)) == 0)
	{
		tmp = link->start_a;
		if (tmp->num != link->max && tmp->num != link->min && link->len_a--)
		{
			commands_pb(link);
			ft_putstr("pb\n");
			link->len_b++;
		}
		else
		{
			commands_ra(link);
			ft_putstr("ra\n");
		}
		output_elem(link);
	}
	sort_start_position(link);
	while (link->len_b > 0 && link->len_b-- && link->len_a++)
	{
		length_in_a(link);
		length_in_b(link);
		choose_the_best(link);
		output_elem(link);
	}
	end(link, 0);
}
