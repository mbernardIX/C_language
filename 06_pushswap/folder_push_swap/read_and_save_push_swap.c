/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_save_push_swap.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:50:30 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:50:31 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	add_stack_push_swap(char *str, t_stack *stack_a)
{
	t_stack *tmp;
	char	*lu;

	lu = NULL;
	tmp = (t_stack*)malloc(sizeof(t_stack));
	if (!tmp)
		exit(0);
	tmp->num = ft_atoi(str);
	tmp->next = NULL;
	tmp->prev = stack_a;
	tmp->oper_a = 0;
	tmp->oper_b = 0;
	stack_a->next = tmp;
	lu = ft_itoa(tmp->num);
	if (ft_strcmp(lu, str) != 0)
		error();
	ft_strdel(lu);
}

void	initialisation(t_link *link, t_stack *stack_a, char *str)
{
	char	*lu;

	lu = NULL;
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
	lu = ft_itoa(stack_a->num);
	if (ft_strcmp(lu, str) != 0)
		error();
	ft_strdel(lu);
}

int		check_mod(char *str, int n)
{
	int	k;

	k = 0;
	if (ft_strcmp(str, "-v") == 0)
		k = 1;
	else if (ft_strcmp(str, "-l") == 0)
		k = 1;
	else if (ft_strcmp(str, "-vl") == 0 || ft_strcmp(str, "-lv") == 0)
		k = 1;
	if (k + 1 >= n)
		exit(0);
	return (k);
}

void	write_mod(int k, char *str, t_link *link)
{
	if (k == 0)
		return ;
	if (ft_strcmp(str, "-v") == 0)
		link->mod_v = true;
	else if (ft_strcmp(str, "-l") == 0)
		link->mod_l = true;
	else if (ft_strcmp(str, "-vl") == 0 || ft_strcmp(str, "-lv") == 0)
	{
		link->mod_v = true;
		link->mod_l = true;
	}
}

t_stack	*reading_for_push_swap(int ac, char **av, t_stack *stack_a)
{
	int		k;
	int		i;
	t_link	*link;

	i = 1;
	k = check_mod(av[1], ac);
	stack_a->num = ft_atoi(av[i + k]);
	if (!(link = (t_link*)malloc(sizeof(t_link))))
		exit(0);
	initialisation(link, stack_a, av[i + k]);
	write_mod(k, av[k], link);
	while (++i + k < ac)
	{
		add_stack_push_swap(av[i + k], stack_a);
		stack_a = stack_a->next;
		link->max = max(link->max, stack_a->num);
		link->min = min(link->min, stack_a->num);
	}
	test_error(link);
	link->len_a = max(i - 2, 0);
	link->end_a = stack_a;
	first_work(link, NULL);
	stack_a = link->start_a;
	free(link);
	return (stack_a);
}
