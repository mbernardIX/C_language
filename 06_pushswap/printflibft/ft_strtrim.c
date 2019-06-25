/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 12:36:50 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/06 15:05:33 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_za(void)
{
	char *d;

	d = ft_strnew(1);
	return (d);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	char	*d;

	if (s == NULL)
		return (0);
	k = 0;
	i = ft_strlen(s);
	while (k <= i && (s[k] == ' ' || s[k] == '\n' || s[k] == '\t'))
		k++;
	i--;
	while (i > 0 && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	if (i <= k)
		return (ft_za());
	d = ft_strnew(i - k);
	if (d == NULL)
		return (0);
	d = ft_strsub(s, k, i - k + 1);
	return (d);
}
