/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:22:41 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/09 15:36:38 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;
	size_t			i;

	dstptr = (unsigned char*)dst;
	srcptr = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dstptr[i] = srcptr[i];
		if (srcptr[i] == (unsigned char)c)
			return ((void*)(dstptr + i + 1));
		i++;
	}
	return (NULL);
}
