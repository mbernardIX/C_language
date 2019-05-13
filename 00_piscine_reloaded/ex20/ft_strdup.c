/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:26:11 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/05 14:23:54 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*dest;
	int				i;
	int				len;

	len = 0;
	i = 0;
	while (src[len] != 0)
		len++;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))) || src == 0)
		return (NULL);
	while (len != 0)
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
