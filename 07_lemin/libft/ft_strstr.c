/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:49:02 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	lenstr;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	lenstr = ft_strlen(needle);
	while (haystack[i])
	{
		k = i;
		while (haystack[k] == needle[j])
		{
			j++;
			k++;
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		k = 0;
		j = 0;
		i++;
	}
	if (needle[j] == '\0')
		return ((char*)haystack);
	return (NULL);
}
