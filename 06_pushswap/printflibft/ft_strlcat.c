/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:39:31 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/10 09:55:25 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t size)
{
	size_t	len;
	size_t	n;

	len = 0;
	n = size;
	while (*dest && n-- && ++len)
		dest++;
	n = size - len;
	if (n-- == 0)
		return (len + ft_strlen(str));
	len += ft_strlen(str);
	while (*str)
	{
		if (n)
		{
			*dest++ = *str;
			n--;
		}
		str++;
	}
	*dest = '\0';
	return (len);
}
