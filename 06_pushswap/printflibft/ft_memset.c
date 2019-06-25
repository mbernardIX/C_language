/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:58:57 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/11 14:58:04 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t l)
{
	unsigned char *ptr;

	ptr = (unsigned char*)b;
	while (l > 0)
	{
		*ptr = (unsigned char)c;
		ptr++;
		l--;
	}
	return (b);
}
