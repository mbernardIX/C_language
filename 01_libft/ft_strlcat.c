/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:42:55 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/11 19:09:23 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len_dst;

	len_dst = 0;
	while (dst[len_dst] != '\0' && len_dst < size)
		len_dst++;
	if (len_dst == size)
		return (size + ft_strlen(src));
	i = len_dst;
	while (i < size - 1 && src[i - len_dst] != '\0')
	{
		dst[i] = src[i - len_dst];
		i++;
	}
	dst[i] = '\0';
	return (len_dst + ft_strlen(src));
}
