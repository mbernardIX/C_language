/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swappoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:48:51 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swappoint(void **a, void **b)
{
	unsigned char	**p;
	unsigned char	**q;
	unsigned char	*tmp;

	if (!a || !b)
		return ;
	p = (unsigned char**)a;
	q = (unsigned char**)b;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
