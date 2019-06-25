/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 21:19:22 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/03 14:20:41 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	n;
	char			*d;

	if (!s || !f)
		return (0);
	d = ft_strnew(ft_strlen(s));
	if (!d)
		return (0);
	n = 0;
	while (s[n])
	{
		d[n] = f(n, s[n]);
		n++;
	}
	d[n] = '\0';
	return (d);
}
