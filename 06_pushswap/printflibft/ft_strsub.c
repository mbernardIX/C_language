/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:46:56 by dspider-          #+#    #+#             */
/*   Updated: 2019/01/08 16:46:28 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;
	char *ptr;

	if (!s || len > len + 1)
		return (NULL);
	if (ft_strlen(s) < (start + len) || len > len + 1 || !s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (s[start] && len--)
		*str++ = s[start++];
	*str = '\0';
	return (ptr);
}
