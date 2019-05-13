/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:33:19 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/11 18:19:18 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	len_small;
	int		i;

	len_small = ft_strlen(small);
	if (len_small == '\0')
		return ((char*)big);
	i = 0;
	while (big[i] != '\0' && i <= (int)(len - len_small))
	{
		if (big[i] == small[0])
			if (!ft_strncmp(big + i, small, len_small))
				return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
