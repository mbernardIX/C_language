/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:55:01 by dspider-          #+#    #+#             */
/*   Updated: 2019/03/02 13:09:22 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"
#include "libftprintf.h"
#include <stdlib.h>

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	if (!(str = (char**)malloc(sizeof(str) * (ft_calc_words(s, c) + 1))))
		return (NULL);
	while (*s)
	{
		if (*s != c && *s)
		{
			str[i] = ft_strnew(ft_calc_letters(s, c));
			if (!str[i])
				return (ft_free_array(str, i));
			ft_strncpy(str[i++], s, ft_calc_letters(s, c));
			while (*s != c && *s)
				s++;
		}
		if (*s)
			s++;
	}
	str[i] = NULL;
	return (str);
}
