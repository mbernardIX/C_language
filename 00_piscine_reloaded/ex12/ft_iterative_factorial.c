/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:14:08 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/05 17:25:50 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	max;
	int	i;

	i = 1;
	max = nb;
	if (nb > 12)
		return (0);
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	nb = 1;
	while (i <= max)
	{
		nb = nb * i;
		i++;
	}
	return (nb);
}
