/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base_little.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:48:33 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(unsigned long long nbr, unsigned long long base)
{
	int i;

	i = 0;
	if (nbr == 0)
		i++;
	while (nbr > 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*ft_utoa_base_little(unsigned long long nbr, int base)
{
	char				*str;
	unsigned long long	len;

	len = nbrlen(nbr, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		if (nbr % base < 10)
			str[--len] = nbr % base + '0';
		else
			str[--len] = nbr % base + 'a' - 10;
		nbr /= base;
	}
	return (str);
}
