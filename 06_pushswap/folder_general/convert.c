/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <mbernard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:48:15 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/19 15:48:17 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**convert(int ac, char **av, int k, char **p)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	str = ft_strdup(av[i + k]);
	i = 1;
	tmp = NULL;
	while (i + k < ac)
	{
		tmp = str;
		str = ft_strjoin(str, " ");
		ft_strdel(tmp);
		tmp = str;
		str = ft_strjoin(str, av[i + k]);
		ft_strdel(tmp);
		i++;
	}
	p = ft_strsplit(str, ' ');
	ft_strdel(str);
	return (p);
}
