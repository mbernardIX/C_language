/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_roun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:19 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_roun(char **celoe, char **drobnoe, int sim, long long i)
{
	unsigned long long		sized;
	unsigned long long		sizec;

	sizec = ft_strlen(*celoe) - 1;
	if (*drobnoe == NULL)
		sized = 0;
	else
		sized = ft_strlen(*drobnoe) - 1;
	if (sim >= 5)
	{
		i = sized;
		while (i >= 0)
		{
			if ((*drobnoe)[i] == '9')
				(*drobnoe)[i] = '0';
			else if ((*drobnoe)[i] < '9')
			{
				(*drobnoe)[i] += 1;
				break ;
			}
			i--;
		}
		if (i == -1)
			ft_roun_celoe(celoe, sizec, i);
	}
}

void		ft_roun_celoe(char **celoe, unsigned long long sizec, long long i)
{
	if ((*celoe)[sizec] < '9')
		(*celoe)[sizec] += 1;
	else
	{
		i = sizec;
		while (i >= 0)
		{
			if ((*celoe)[i] == '9')
				(*celoe)[i] = '0';
			else if ((*celoe)[i] < '9')
			{
				(*celoe)[i] += 1;
				break ;
			}
			if ((*celoe)[i] == '-' && i == 0)
			{
				(*celoe)[i] = '1';
				*celoe = ft_strjoin_free("-", *celoe, 0, 1);
			}
			if (i == 0 && (*celoe)[i] == '0')
				*celoe = ft_strjoin_free("1", *celoe, 0, 1);
			i--;
		}
	}
}
