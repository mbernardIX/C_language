/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 14:54:39 by dspider-          #+#    #+#             */
/*   Updated: 2019/03/02 13:19:07 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"
#include <stdlib.h>

char	**ft_free_array(char **str, int i)
{
	if (!str)
		return (NULL);
	while (i)
		ft_strdel(str[--i]);
	free(str);
	return (NULL);
}
