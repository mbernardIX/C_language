/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 15:08:05 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/09 12:50:39 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int src, size_t len)
{
	unsigned char *a;

	a = str;
	while (len-- > 0)
		*a++ = (unsigned char)src;
	return (str);
}
