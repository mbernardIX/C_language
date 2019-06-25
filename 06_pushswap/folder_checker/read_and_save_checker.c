/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_save_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:48:00 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:48:02 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_stack_checker(char *str, t_stack *stack_a)
{
	t_stack *tmp;
	char	*lu;

	lu = NULL;
	tmp = (t_stack*)malloc(sizeof(t_stack));
	tmp->num = ft_atoi(str);
	tmp->next = NULL;
	tmp->prev = stack_a;
	stack_a->next = tmp;
	lu = ft_itoa(tmp->num);
	if (ft_strcmp(lu, str) != 0)
		error();
	ft_strdel(lu);
}

void	initialisation(t_link *link, t_stack *stack_a)
{
	stack_a->next = NULL;
	stack_a->prev = NULL;
	stack_a->oper_a = 0;
	stack_a->oper_b = 0;
	link->start_b = NULL;
	link->end_b = NULL;
	link->len_b = 0;
	link->start_a = stack_a;
	link->max = stack_a->num;
	link->min = stack_a->num;
	link->mod_l = false;
	link->mod_v = false;
}

t_stack	*reading_for_check(int ac, char **av, t_stack *stack_a)
{
	int		i;
	t_link	*link;
	char	*lu;

	i = 1;
	stack_a->num = ft_atoi(av[i]);
	if (!(link = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	initialisation(link, stack_a);
	lu = ft_itoa(stack_a->num);
	if (ft_strcmp(lu, av[i]) != 0)
		error();
	ft_strdel(lu);
	while (++i < ac)
	{
		add_stack_checker(av[i], stack_a);
		stack_a = stack_a->next;
	}
	test_error(link);
	link->end_a = stack_a;
	output_elem(link);
	recieve_commands(link);
	stack_a = link->start_a;
	free(link);
	return (stack_a);
}
