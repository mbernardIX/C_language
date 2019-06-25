/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:50:33 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t sizedst;
	size_t sizesrc;

	j = 0;
	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	if (size > sizedst)
	{
		size = size - sizedst - 1;
		while (src[j] != '\0' && size > j)
		{
			dst[sizedst + j] = src[j];
			j++;
		}
		dst[sizedst + j] = '\0';
		return (sizedst + sizesrc);
	}
	return (sizesrc + size);
}
