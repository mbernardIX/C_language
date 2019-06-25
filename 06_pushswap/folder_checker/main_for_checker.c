/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:47:52 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:47:56 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int ac, char **av)
{
	int		i;
	t_stack *stack_a;
	char	**p;
	t_stack	*tmp;

	i = 0;
	p = NULL;
	if (ac >= 2)
	{
		if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
			exit(0);
		p = convert(ac, av, 0, p);
		while (p[i])
			i++;
		stack_a = reading_for_check(i, p, stack_a);
		while (stack_a)
		{
			tmp = stack_a->next;
			free(stack_a);
			stack_a = tmp;
		}
	}
	ft_free_array(p, i);
	return (0);
}
