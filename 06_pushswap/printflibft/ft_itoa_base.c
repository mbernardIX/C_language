/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:49:56 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/04 16:40:17 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_len_base(unsigned long a, int base)
{
	int	i;

	i = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a /= base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base(unsigned long n, int base, int t)
{
	char	*res;
	int		len;
	int		k;

	len = calc_len_base(n, base);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	if ((k = n % base) > 9)
		res[--len] = 'a' + n % base - 10 + t;
	else
		res[--len] = n % base + '0';
	n /= base;
	while (n > 0)
	{
		if ((k = n % base) > 9)
			res[--len] = 'a' + n % base - 10 + t;
		else
			res[--len] = n % base + '0';
		n /= base;
	}
	return (res);
}
