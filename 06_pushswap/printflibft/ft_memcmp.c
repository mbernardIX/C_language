/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:07:34 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/09 15:41:32 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char *ptr;
	const char *sa;

	ptr = s1;
	sa = s2;
	while (n > 0)
	{
		n--;
		if ((unsigned int)(*ptr - *sa) != 0)
			return (*(unsigned char*)ptr - *(unsigned char*)sa);
		sa++;
		ptr++;
	}
	return (0);
}
