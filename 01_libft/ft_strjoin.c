/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 13:39:58 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/22 17:10:30 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	str = (char*)malloc((lens1 + lens2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < lens1)
	{
		str[i] = s1[i];
		i++;
	}
	while (i - lens1 < lens2)
	{
		str[i] = s2[i - lens1];
		i++;
	}
	str[i] = '\0';
	return (str);
}
