/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:04:11 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/06 11:00:41 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int		ft_printf(const char *str, ...)
{
	va_list			args;
	t_print			*list;
	unsigned long	n;

	list = (t_print*)malloc(sizeof(t_print));
	list->answer = 0;
	va_start(args, str);
	reading(str, args, list);
	n = list->answer;
	va_end(args);
	free(list);
	return (n);
}
