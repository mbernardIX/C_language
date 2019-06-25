/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_push_swap.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:50:11 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:50:12 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack	*tmp;
	char	**p;
	int		i;

	p = NULL;
	i = 0;
	if (ac >= 2)
	{
		stack_a = (t_stack*)malloc(sizeof(t_stack));
		if (!stack_a)
			exit(0);
		p = convert(ac, av, 0, p);
		while (p[i])
			i++;
		stack_a = reading_for_push_swap(i, p, stack_a);
		while (stack_a)
		{
			tmp = stack_a->next;
			free(stack_a);
			stack_a = tmp;
		}
		ft_free_array(p, i);
	}
	return (0);
}
