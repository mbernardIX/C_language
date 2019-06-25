/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_for_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:53:28 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_swap_atoi(const char *str)
{
	int				i;
	long long int	res;
	int				otr;

	i = 0;
	res = 0;
	otr = 1;
	while (str[i] != '\0')
		i++;
	if (i > 11)
		ft_error_ps();
	i = 0;
	if (str[i] == '-')
		otr = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res * 10 / 10) != res)
			return ((otr == 1) ? -1 : 0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * otr);
}
