/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:24:37 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/10 15:04:25 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *small)
{
	int	len_small;
	int	len_big;
	int	i;
	int	j;

	if (*small == '\0')
		return ((char*)big);
	len_small = ft_strlen(small);
	len_big = ft_strlen(big);
	i = 0;
	while (i <= len_big - len_small)
	{
		j = 0;
		while (j < len_small && big[i + j] == small[j])
			j++;
		if (j == len_small)
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
