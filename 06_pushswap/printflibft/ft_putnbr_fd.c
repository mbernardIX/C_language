/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:10:16 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/06 15:10:17 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_coutfd(int i, int j, int nb, int fd)
{
	int c;

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
		ft_putchar_fd('0' + c, fd);
		i--;
	}
}

void		ft_putnbr_fd(int nb, int fd)
{
	int i;
	int c;
	int j;

	i = 0;
	j = 0;
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar_fd('-', fd);
	}
	c = nb;
	if (c == 0)
		ft_putchar_fd('0', fd);
	while (c != 0 && ++i)
		c = c / 10;
	ft_coutfd(i, j, nb, fd);
}
