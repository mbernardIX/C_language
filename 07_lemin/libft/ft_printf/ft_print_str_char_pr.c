/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_char_pr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:10 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_procent(t_print *po)
{
	if (po->width)
	{
		po->width--;
		while (po->width && po->minus == 0)
		{
			if (po->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			po->width--;
			po->returnsize++;
		}
		ft_putchar('%');
		while (po->width && po->minus > 0)
		{
			ft_putchar(' ');
			po->width--;
			po->returnsize++;
		}
		po->returnsize++;
		return (1);
	}
	ft_putchar('%');
	po->returnsize += 1;
	return (1);
}

int			ft_print_char(t_print *po, char sim)
{
	if (po->width)
	{
		po->width--;
		while (po->width && po->minus == 0)
		{
			if (po->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
			po->width--;
			po->returnsize++;
		}
		ft_putchar(sim);
		while (po->width && po->minus > 0)
		{
			ft_putchar(' ');
			po->width--;
			po->returnsize++;
		}
		po->returnsize++;
		return (1);
	}
	ft_putchar(sim);
	po->returnsize += 1;
	return (1);
}

void		ft_space_string(char *str, t_print *po)
{
	int sizestr;

	sizestr = ft_strlen(str);
	if (po->accuracy > 0)
		str = ft_accuracy_string(str, po, sizestr);
	else
		po->returnsize += sizestr;
	while (po->width > sizestr && po->minus == 0)
	{
		if (po->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		po->width--;
		po->returnsize++;
	}
	ft_putstr((char*)str);
	if (po->accuracfree == 1)
		free(str);
	while (po->width > sizestr && po->minus == 1)
	{
		ft_putchar(' ');
		po->width--;
		po->returnsize++;
	}
}

char		*ft_accuracy_string(char *str, t_print *po, int sizestr)
{
	if (po->accuracy < sizestr)
	{
		sizestr -= po->accuracy;
		po->width += sizestr;
	}
	str = ft_strsub(str, 0, po->accuracy);
	po->returnsize += (int)ft_strlen(str);
	po->accuracfree = 1;
	return (str);
}

int			ft_print_string(t_print *po, va_list ap)
{
	char *str;

	str = va_arg(ap, char*);
	if (po->accuracy == -1 && po->width == 0)
		return (1);
	if (po->accuracy == -1 && po->width > 0)
		str = " ";
	if (po->accuracy == -1 && po->width > 0 && po->zero == 1)
		str = "0";
	if (str == NULL)
		str = "(null)";
	ft_space_string(str, po);
	return (1);
}
