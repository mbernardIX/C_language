/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:52:26 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned const char	*copystr;

	i = 0;
	str = dst;
	copystr = src;
	while (i < n)
	{
		str[i] = copystr[i];
		if (copystr[i] == (unsigned char)c)
		{
			return ((unsigned char*)&str[i + 1]);
		}
		i++;
	}
	return (NULL);
}
