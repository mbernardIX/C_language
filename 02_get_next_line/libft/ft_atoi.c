/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbernard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 20:48:16 by mbernard          #+#    #+#             */
/*   Updated: 2019/04/12 18:11:18 by mbernard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && str[i] >= '0' && (str[i] <= '9'))
	{
		if ((result > 922337203685477580 || (result == 922337203685477580
						&& (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((result > 922337203685477580 || (result == 922337203685477580
						&& (str[i] - '0') > 8)) && sign == -1)
			return (0);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
