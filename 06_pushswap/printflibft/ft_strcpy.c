/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 10:16:23 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/10 09:54:32 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *str)
{
	char		*g;
	const char	*s;
	size_t		n;

	n = ft_strlen(str);
	g = dest;
	s = str;
	return (ft_strncpy(g, s, 1 + n));
}
