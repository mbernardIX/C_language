/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:03:17 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/10 09:54:53 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *str, size_t n)
{
	size_t	i;
	char	*s;

	s = dest;
	i = 0;
	while (i++ < n)
	{
		if (*str)
			*dest++ = *str++;
		else
			*dest++ = '\0';
	}
	return (s);
}
