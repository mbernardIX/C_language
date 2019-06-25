/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:31 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_space(char *str, t_print *po, int sizestr)
{
	hp_check_space(str, po, sizestr);
	if (po->space == 1 && str[0] != '-' && po->plus == 0
			&& po->width <= sizestr && po->minus == 0)
	{
		ft_putchar(' ');
		po->returnsize++;
		po->width--;
	}
	if (str[0] != '+' && str[0] != '-' && po->plus == 1 && po->width < sizestr)
	{
		ft_putchar('+');
		po->returnsize++;
		po->plus = 0;
		po->width--;
	}
	if (*str != '-' && po->plus == 1 && po->width > sizestr && po->zero == 1)
	{
		ft_putchar('+');
		po->plus = 0;
		po->returnsize++;
		po->width--;
	}
}

void		ft_space_string_dec(char *str, t_print *po, int sizestr)
{
	sizestr += (int)ft_strlen(str);
	po->returnsize += sizestr;
	if (po->plus == 1 || po->space == 1)
		ft_check_space(str, po, sizestr);
	if (po->space == 1 && po->width > 0 && po->zero == 1
		&& po->minus == 0 && *str != '-')
	{
		ft_putchar(' ');
		po->returnsize++;
		po->width--;
	}
	if (*str == '-' && po->width > sizestr && po->zero == 1)
	{
		ft_putchar('-');
		str++;
	}
	hp_space_string_dec(str, po, sizestr);
	ft_putstr((char*)str);
	while (po->width > sizestr && po->minus == 1)
	{
		ft_putchar(' ');
		po->width--;
		po->returnsize++;
	}
}

void		ft_print_accuracy_dec(char *str, t_print *po,
	int sizestr)
{
	sizestr = (int)ft_strlen(str);
	if (po->accuracy < sizestr)
	{
		po->zero = 0;
		ft_space_string_dec(str, po, 0);
		return ;
	}
	if (po->accuracy >= sizestr)
	{
		po->accuracy -= sizestr;
		if (*str == '-')
		{
			po->accuracy++;
			str++;
			if (po->width <= po->accuracy)
			{
				ft_putchar('-');
				po->minus = 0;
			}
		}
	}
	hp_print_accuracy_dec(str, po, sizestr);
	if (po->width > po->accuracy)
		ft_space_accuracy_dec(str, po, sizestr);
	hp2_print_accuracy_dec(str, po, sizestr);
}

void		ft_space_accuracy_dec(char *str, t_print *po, int sizestr)
{
	if (po->plus == 1 && *str != '-' &&
		str[0 - 1] != '-' && po->width > po->accuracy)
	{
		po->width--;
	}
	po->accuracy += sizestr;
	po->width -= po->accuracy;
	while (0 < po->width && po->minus == 0)
	{
		ft_putchar(' ');
		po->returnsize++;
		po->width--;
	}
	if (*str == '-' || str[0 - 1] == '-')
	{
		ft_putchar('-');
	}
	if (po->plus == 1 && *str != '-' && str[0 - 1] != '-')
	{
		ft_putchar('+');
		po->returnsize++;
	}
	po->accuracy -= sizestr;
	po->infuncheck = 1;
}

int			ft_print_int(t_print *po, va_list ap)
{
	char				*str;

	str = ft_add_d_mod_length(po, ap, 0);
	if (po->accuracy == -1 && *str == '0' && po->width == 0 && po->space == 0)
		return (1);
	if (po->accuracy == -1 && *str == '0' && po->width > 0)
		*str = ' ';
	if (po->accuracy == -1 && *str == '0' && po->width == 0 && po->space == 1)
	{
		ft_putchar(' ');
		po->returnsize++;
		return (1);
	}
	if (po->accuracy == 0)
		ft_space_string_dec(str, po, 0);
	else
		ft_print_accuracy_dec(str, po, 0);
	free(str);
	return (1);
}
