/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:54:59 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_parse_format(char *format, t_print *po, va_list ap)
{
	while (format[po->i] != '\0')
	{
		ft_clear_struct(po);
		if (format[po->i] == '%' && format[po->i + 1] != '\0')
		{
			po->i++;
			if (ft_check_valid_param(format, po->i, po) == 1
				|| format[po->i] == '%')
				ft_param(format, po, ap);
		}
		else if (format[po->i] != '\0' && format[po->i] != '%')
		{
			ft_putchar(format[po->i]);
			po->returnsize++;
			po->i++;
		}
		else
			po->i++;
	}
}

void		ft_param(char *format, t_print *po, va_list ap)
{
	while (ft_type(format, po, ap) == 0 && format[po->i] != '\0')
	{
		ft_flags(format, po);
		ft_width_param(format, po);
		ft_accuracy(format, po);
		ft_mod_length(format, po);
	}
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_print *po;
	int		size;

	po = NULL;
	size = 0;
	po = ft_struct_creat(po);
	if (format)
	{
		va_start(ap, format);
		ft_parse_format((char*)format, po, ap);
		va_end(ap);
	}
	size = po->returnsize;
	free(po);
	return (size);
}

int			ft_check_valid_param(char *str, int i, t_print *po)
{
	int try;
	int r;

	r = i;
	try = 0;
	while (str[i] == '#' || str[i] == '-' || str[i] == '+' || str[i] == ' '
		|| str[i] == '0' || str[i] == 'l' || str[i] == 'h' || str[i] == '.'
		|| ft_isdigit(str[i]) || str[i] == 'L' || str[i] == '*')
		i++;
	if (str[i] == 'u' || str[i] == 's' || str[i] == 'd' || str[i] == 'i'
		|| str[i] == 'x' || str[i] == 'X' || str[i] == 'p' || str[i] == '%'
		|| str[i] == 'c' || str[i] == 'o' || str[i] == '\0' || str[i] == 'f')
		try++;
	else
	{
		if (i > r)
			po->i += i - 1;
	}
	return (try);
}
