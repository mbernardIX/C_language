/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:23:48 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/07 11:25:48 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strplace(int ac, int i, char *s1, char **str)
{
	int j;
	int index;

	index = 0;
	j = 1;
	while (j < ac)
	{
		if (j != i && ft_strcmp(s1, str[j]) > 0)
			index++;
		if (j < i && ft_strcmp(s1, str[j]) == 0)
			index++;
		j++;
	}
	return (index);
}

void		ft_sort_params(int ac, char **av)
{
	int		i;
	int		graf[256];
	int		index;

	i = 1;
	while (i < ac)
	{
		index = ft_strplace(ac, i, av[i], av);
		index++;
		graf[index] = i;
		i++;
	}
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[graf[i]]);
		ft_putchar('\n');
		i++;
	}
}
