/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:50:02 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/10 09:53:53 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s, const char *q, size_t n)
{
	char *ans;

	ans = ft_strnew(ft_strlen(q));
	ft_strncpy(ans, q, n);
	return (ft_strcat(s, ans));
}
