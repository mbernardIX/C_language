/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:02 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_big_x(t_print *po, va_list ap)
{
	char *str;
	char *tmp;

	str = ft_add_b_x_mod_length(po, ap, 0);
	if (po->accuracy == -1 && *str == '0' && po->width == 0)
		return (1);
	if (po->accuracy == -1 && *str == '0' && po->width > 0)
		*str = ' ';
	if (po->sharp == 1 && *str != '0' && po->zero == 0 && po->accuracy <= 0)
	{
		tmp = str;
		str = ft_strjoin("0X", str);
		free(tmp);
		po->sharp = 0;
	}
	po->plus = 0;
	if (po->accuracy == 0)
		ft_space_string_x_big(str, po, 0);
	else
		ft_print_accuracy_x_b(str, po, 0, 0);
	free(str);
	return (1);
}

int			ft_print_little_x(t_print *po, va_list ap)
{
	char *str;
	char *tmp;

	str = ft_add_l_x_mod_length(po, ap, 0);
	if (po->accuracy == -1 && *str == '0' && po->width == 0)
		return (1);
	if (po->accuracy == -1 && *str == '0' && po->width > 0)
		*str = ' ';
	if (po->sharp == 1 && *str != '0' && po->zero == 0 && po->accuracy <= 0)
	{
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
		po->sharp = 0;
	}
	po->plus = 0;
	if (po->accuracy == 0)
		ft_space_string_x_little(str, po, 0);
	else
		ft_print_accuracy_x_l(str, po, 0, 0);
	free(str);
	return (1);
}

void		ft_print_accuracy_x_b(char *str, t_print *po,
	int sizestr, int saveacc)
{
	saveacc = po->accuracy;
	sizestr = ft_strlen(str);
	if (po->accuracy < sizestr)
	{
		ft_space_string_x_big(str, po, 0);
		return ;
	}
	if (po->accuracy >= sizestr)
		po->accuracy -= sizestr;
	po->width -= po->accuracy + sizestr;
	if (po->sharp == 1 && *str != '0')
		po->width -= 2;
	while (0 < po->width && po->minus == 0)
	{
		ft_putchar(' ');
		po->returnsize++;
		po->width--;
	}
	if (po->sharp == 1 && *str != '0')
	{
		ft_putstr("0X");
		po->returnsize += 2;
	}
	hp2_print_accuracy_dec_x(str, po, sizestr);
}

void		ft_print_accuracy_x_l(char *str, t_print *po,
	int sizestr, int saveacc)
{
	saveacc = po->accuracy;
	sizestr = ft_strlen(str);
	if (po->accuracy < sizestr)
	{
		ft_space_string_x_little(str, po, 0);
		return ;
	}
	if (po->accuracy >= sizestr)
		po->accuracy -= sizestr;
	po->width -= po->accuracy + sizestr;
	if (po->sharp == 1 && *str != '0')
		po->width -= 2;
	while (0 < po->width && po->minus == 0)
	{
		ft_putchar(' ');
		po->returnsize++;
		po->width--;
	}
	if (po->sharp == 1 && *str != '0')
	{
		ft_putstr("0x");
		po->returnsize += 2;
	}
	hp2_print_accuracy_dec_x(str, po, sizestr);
}

void		hp2_print_accuracy_dec_x(char *str, t_print *po, int sizestr)
{
	while (po->accuracy > 0)
	{
		ft_putchar('0');
		po->accuracy--;
		po->returnsize++;
		if (po->infuncheck == 1)
			po->width--;
	}
	ft_putstr(str);
	while (po->width > 0 && po->minus == 1)
	{
		ft_putchar(' ');
		po->returnsize++;
		po->width--;
	}
	po->returnsize += sizestr;
}
