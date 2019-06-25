/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:49:58 by dspider-          #+#    #+#             */
/*   Updated: 2019/03/02 10:41:34 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	char	*ptr;
	char	*start;

	start = NULL;
	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	ptr = str;
	start = s1;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	s1 = start;
	*str = '\0';
	return (ptr);
}
