/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 10:46:59 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/11 14:59:13 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *sr, size_t len)
{
	if (sr >= dest)
		return (ft_memcpy(dest, sr, len));
	else
	{
		len--;
		dest += len;
		sr += len;
		len++;
		while (len-- > 0)
		{
			*(char*)dest = *(const char*)sr;
			sr--;
			dest--;
		}
		dest++;
	}
	return (dest);
}
