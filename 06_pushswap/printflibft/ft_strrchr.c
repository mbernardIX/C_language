/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:35:07 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/01 19:09:08 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		q;

	i = 0;
	q = -1;
	if (ft_isascii(c) == 0)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			q = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char*)&s[i]);
	if (q != -1)
		return ((char*)&s[q]);
	return (0);
}
