/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:15:39 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/07 11:16:06 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fibonacci(int index)
{
	int mul;

	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	else
	{
		if (index == 1 || index == 2)
			return (1);
		mul = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
		return (mul);
	}
}
