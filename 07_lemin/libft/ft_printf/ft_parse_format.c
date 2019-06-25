/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:25 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_type(char *format, t_print *po, va_list ap)
{
	int stop;

	stop = 0;
	if (format[po->i] == '%')
		stop = ft_print_procent(po);
	if (format[po->i] == 'c')
		stop = ft_print_char(po, (char)va_arg(ap, int));
	if (format[po->i] == 's')
		stop = ft_print_string(po, ap);
	if (format[po->i] == 'd' || format[po->i] == 'i')
		stop = ft_print_int(po, ap);
	if (format[po->i] == 'u')
		stop = ft_print_u(po, ap);
	if (format[po->i] == 'o')
		stop = ft_print_o(po, ap);
	if (format[po->i] == 'X')
		stop = ft_print_big_x(po, ap);
	if (format[po->i] == 'x')
		stop = ft_print_little_x(po, ap);
	if (format[po->i] == 'p')
		stop = ft_print_p(po, ap);
	if (format[po->i] == 'f')
		stop = ft_print_float(po, ap, 0, NULL);
	po->i += stop;
	return (stop);
}

void		ft_flags(char *format, t_print *po)
{
	while (format[po->i] == '0' || format[po->i] == ' ' ||
		format[po->i] == '#' || format[po->i] == '+' || format[po->i] == '-')
	{
		if (format[po->i] == '0')
			po->zero = 1;
		if (format[po->i] == ' ')
			po->space = 1;
		if (format[po->i] == '#')
			po->sharp = 1;
		if (format[po->i] == '+')
			po->plus = 1;
		if (format[po->i] == '-')
			po->minus = 1;
		if (po->minus == 1 && po->zero == 1)
			po->zero = 0;
		po->i++;
	}
}

void		ft_width_param(char *format, t_print *po)
{
	while (format[po->i] >= '0' && format[po->i] <= '9')
	{
		po->width = 0;
		if (format[po->i] == '*')
		{
			po->width = 1;
		}
		if (format[po->i] >= '0' && format[po->i] <= '9')
		{
			while (format[po->i] >= '0' && format[po->i] <= '9')
			{
				po->width = po->width * 10 + format[po->i] - '0';
				po->i++;
			}
		}
	}
}

void		ft_accuracy(char *format, t_print *po)
{
	if (format[po->i] == '.')
	{
		po->i++;
		po->accuracy = 0;
		if (format[po->i] == '*')
		{
			po->accuracy = 1;
		}
		while (format[po->i] >= '0' && format[po->i] <= '9')
		{
			po->accuracy = po->accuracy * 10 + format[po->i] - '0';
			po->i++;
		}
		if (po->accuracy == 0)
			po->accuracy = -1;
	}
}

void		ft_mod_length(char *format, t_print *po)
{
	if (format[po->i] == 'h' && format[po->i + 1] == 'h')
	{
		po->length = HH;
		po->i += 2;
		return ;
	}
	if (format[po->i] == 'l' && format[po->i + 1] == 'l')
	{
		po->length = LL;
		po->i += 2;
		return ;
	}
	while (format[po->i] == 'h' || format[po->i] == 'l' || format[po->i] == 'L')
	{
		if (format[po->i] == 'h')
			po->length = H;
		if (format[po->i] == 'l')
			po->length = L;
		if (format[po->i] == 'L')
			po->length = LLL;
		po->i++;
	}
}
