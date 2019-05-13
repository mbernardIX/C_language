/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:40:15 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/03 17:42:28 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*a;
	int	i;

	a = NULL;
	if (min < max)
	{
		a = (int*)malloc(sizeof(*a) * (max - min));
		i = 0;
		while (min < max)
		{
			a[i] = min;
			i++;
			min++;
		}
	}
	return (a);
}
