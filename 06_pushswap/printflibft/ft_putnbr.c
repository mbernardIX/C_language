/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:11:07 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/06 15:11:38 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cout(int i, int j, int c, int nb)
{
	while (i > 0)
	{
		c = nb;
		j = i - 1;
		while (j > 0)
		{
			c = c / 10;
			j--;
		}
		c = c % 10;
		ft_putchar('0' + c);
		i--;
	}
}

void		ft_putnbr(int nb)
{
	int i;
	int c;
	int j;

	i = 0;
	j = 0;
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	c = nb;
	if (c == 0)
		ft_putchar('0');
	while (c != 0 && ++i)
		c = c / 10;
	ft_cout(i, j, nb, nb);
}
