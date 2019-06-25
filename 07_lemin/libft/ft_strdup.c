/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:50:48 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*strmall;
	unsigned long	size;
	unsigned long	i;

	size = 0;
	i = 0;
	while (s1[size])
	{
		size++;
	}
	strmall = (char*)malloc((size + 1) * sizeof(char));
	if (!strmall)
		return (NULL);
	while (s1[i])
	{
		strmall[i] = s1[i];
		i++;
	}
	strmall[i] = '\0';
	return (strmall);
}
