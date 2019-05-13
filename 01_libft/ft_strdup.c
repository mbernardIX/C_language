/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:03:11 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/22 18:14:23 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while (s1[len] != 0)
		len++;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))) || s1 == 0)
		return (NULL);
	while (len != 0)
	{
		dest[i] = s1[i];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
