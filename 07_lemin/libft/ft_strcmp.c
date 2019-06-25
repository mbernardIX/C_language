/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:50:58 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*lenstr1;
	unsigned char	*lenstr2;

	lenstr1 = (unsigned char *)(s1);
	lenstr2 = (unsigned char *)(s2);
	while (*lenstr1 == *lenstr2 && *lenstr1)
	{
		lenstr1++;
		lenstr2++;
	}
	return ((unsigned int)*lenstr1 - (unsigned int)*lenstr2);
}
