/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 19:59:29 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/05 12:30:03 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	i = 0;
	if (str2[j] == '\0')
		return ((char*)str1);
	while (str1[i] && i < n)
	{
		if (str1[i] == str2[0])
		{
			while (str1[i] && str2[j] && str1[i + j] == str2[j] && i + j < n)
				j++;
			if (str2[j] == '\0')
				return ((char*)&str1[i]);
			j = 0;
		}
		i++;
	}
	return (0);
}
