/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:52:19 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*strone;
	unsigned char	*strtwo;
	size_t			i;

	strone = (unsigned char*)s1;
	strtwo = (unsigned char*)s2;
	i = 0;
	while (n > i)
	{
		if (strone[i] == strtwo[i])
		{
			i++;
		}
		else
			return (strone[i] - strtwo[i]);
	}
	return (0);
}
