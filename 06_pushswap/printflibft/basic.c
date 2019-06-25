/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 13:40:40 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/26 09:38:37 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	max(long a, long b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

long	min(long a, long b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

char	*rev_str(char *str, long len)
{
	char	*new;
	long	i;

	if (str == NULL)
		return (NULL);
	i = 0;
	new = ft_strnew(len);
	while (i < len)
	{
		new[i] = str[len - i - 1];
		i++;
	}
	ft_strdel(str);
	return (new);
}
