/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:51:54 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/10 09:52:42 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	i;
	size_t	j;
	char	*g;

	g = (char*)str1;
	i = ft_strlen(str1);
	j = ft_strlen(str2);
	if (j == 0)
		return (g);
	while (i > 0)
	{
		g = ft_strnew(j);
		g = ft_strncpy(g, str1, j);
		if (ft_strcmp(g, str2) == 0)
			return ((char*)str1);
		str1++;
		i--;
	}
	return (0);
}
