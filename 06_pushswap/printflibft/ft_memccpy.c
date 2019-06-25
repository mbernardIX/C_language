/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:39:36 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/11 15:20:38 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *str, int c, size_t n)
{
	char	*g;
	char	*pt;

	g = (char*)dst;
	pt = (char*)str;
	while (n > 0)
	{
		*g = *pt;
		g++;
		if ((unsigned char)*pt == (unsigned char)c)
			return (g++);
		pt++;
		n--;
	}
	return (0);
}
