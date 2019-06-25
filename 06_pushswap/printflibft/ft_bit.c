/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 12:31:24 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/09 15:22:22 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		bit_return(int a, int i)
{
	int buf;

	buf = a & 1 << i;
	if (buf == 0)
		return (0);
	else
		return (1);
}

void	ft_bit(char *str, int *a, int i)
{
	while (i >= 0)
	{
		*str = (char)bit_return(*a, i);
		str++;
		i--;
	}
}
