/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:55:06 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/11 15:02:26 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *str, size_t n)
{
	char	*q;
	char	*g;

	if (dest == str || n == 0)
		return (dest);
	q = (char*)dest;
	g = (char*)str;
	while (n > 0)
	{
		*q = *g;
		q++;
		g++;
		n--;
	}
	return (dest);
}
