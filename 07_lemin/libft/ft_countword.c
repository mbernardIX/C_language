/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:54:24 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countword(char *str, char c)
{
	int inword;
	int i;
	int word;

	word = 0;
	inword = 0;
	i = 0;
	while (str[i])
	{
		if (inword && str[i] == c)
		{
			inword = 0;
		}
		if (!inword && str[i] != c)
		{
			word++;
			inword = 1;
		}
		i++;
	}
	return (word);
}
