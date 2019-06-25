/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:10:40 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/01 13:13:18 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap_char(char *s, char *d)
{
	char	c;

	c = *s;
	*s = *d;
	*d = c;
}
