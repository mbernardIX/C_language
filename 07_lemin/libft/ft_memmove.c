/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:52:09 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strl1;
	unsigned char	*strl2;
	size_t			i;

	if (dst == src)
		return (dst);
	i = 0;
	strl2 = (unsigned char*)src;
	strl1 = (unsigned char*)dst;
	if (strl2 > strl1)
		while (i < len)
		{
			strl1[i] = strl2[i];
			i++;
		}
	else
		while (len--)
		{
			*(strl1 + len) = *(strl2 + len);
		}
	return (dst);
}
