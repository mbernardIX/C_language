/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 19:24:03 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/09 15:41:05 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	void *ptr;

	ptr = (void*)malloc(sizeof(void) * n);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, n);
	return (&ptr[0]);
}
