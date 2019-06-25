/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_for_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:54:53 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		hp_print_0x_little(t_print *po, char *str)
{
	if (po->width <= 0)
		if (po->accuracy < (int)ft_strlen(str) && *str != '0' && po->accuracy
				&& po->sharp == 1)
		{
			po->width -= 2;
			return ;
		}
	if (po->accuracy <= po->width && po->accuracy > 0)
		po->zero = 0;
	if (po->sharp == 1 && po->zero == 1 && po->width > 0 && *str != '0')
	{
		ft_putstr("0x");
		po->width -= 2;
		po->returnsize += 2;
		po->sharp = 0;
		return ;
	}
}

void		ft_space_string_x_little(char *str, t_print *po, int sizestr)
{
	sizestr = ft_strlen(str);
	po->returnsize += sizestr;
	if (po->accuracy != -1)
		hp_print_0x_little(po, str);
	if (po->sharp == 1 && *str != '0' && po->width >
		po->accuracy && *str != ' ' && po->minus == 0)
		po->width -= 2;
	while (po->width > sizestr && po->minus == 0)
	{
		if (po->zero == 1 && po->accuracy == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		po->width--;
		po->returnsize++;
	}
	if (po->sharp == 1 && *str != '0' && *str != ' ')
	{
		ft_putstr("0x");
		po->width -= 2;
		po->returnsize += 2;
	}
	ft_putstr((char*)str);
	hp_norm_space_x(po, sizestr);
}

void		hp_print_0x_big(t_print *po, char *str)
{
	if (po->width <= 0)
		if (po->accuracy < (int)ft_strlen(str) && *str != '0' && po->accuracy
			&& po->sharp == 1)
		{
			po->width -= 2;
			return ;
		}
	if (po->accuracy <= po->width && po->accuracy > 0)
		po->zero = 0;
	if (po->sharp == 1 && po->zero == 1 && po->width > 0 && *str != '0')
	{
		ft_putstr("0X");
		po->width -= 2;
		po->returnsize += 2;
		po->sharp = 0;
		return ;
	}
}

void		ft_space_string_x_big(char *str, t_print *po, int sizestr)
{
	sizestr = ft_strlen(str);
	po->returnsize += sizestr;
	if (po->accuracy != -1)
		hp_print_0x_big(po, str);
	if (po->sharp == 1 && *str != '0' && po->width >
		po->accuracy && *str != ' ' && po->minus == 0)
		po->width -= 2;
	while (po->width > sizestr && po->minus == 0)
	{
		if (po->zero == 1 && po->accuracy == 0)
			ft_putchar('0');
		else
			ft_putchar(' ');
		po->width--;
		po->returnsize++;
	}
	if (po->sharp == 1 && *str != '0' && *str != ' ')
	{
		ft_putstr("0X");
		po->width -= 2;
		po->returnsize += 2;
	}
	ft_putstr((char*)str);
	hp_norm_space_x(po, sizestr);
}

void		hp_norm_space_x(t_print *po, int sizestr)
{
	while (po->width > sizestr && po->minus == 1)
	{
		ft_putchar(' ');
		po->width--;
		po->returnsize++;
	}
}
