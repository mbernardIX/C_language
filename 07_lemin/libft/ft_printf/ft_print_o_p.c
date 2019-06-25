/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:28 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_o(t_print *po, va_list ap)
{
	char *str;
	char *tmp;

	str = ft_add_o_mod_length(po, ap, 0);
	if (po->accuracy == -1 && *str == '0' && po->width == 0 && po->sharp == 0)
		return (1);
	if (po->accuracy == -1 && *str == '0' && po->width > 0 && po->sharp == 0)
		*str = ' ';
	if (po->sharp == 1 && *str != '0')
	{
		tmp = str;
		str = ft_strjoin("0", str);
		free(tmp);
	}
	po->plus = 0;
	if (po->accuracy == 0)
		ft_space_string_u(str, po);
	else
		ft_print_accuracy_u(str, po, 0, 0);
	free(str);
	return (1);
}

int		ft_print_p(t_print *po, va_list ap)
{
	char *str;
	char *tmp;

	str = ft_add_l_p_mod_length(po, ap, 0);
	if (ft_print_help_p(po, str) == 0)
		return (1);
	if (po->accuracy == -1 && *str == '0' && po->width > 0)
		*str = ' ';
	else if (po->width > 0 && po->zero == 0 && po->accuracy < po->width)
	{
		tmp = str;
		str = ft_strjoin("0x", str);
		free(tmp);
	}
	else
	{
		ft_putstr("0x");
		po->returnsize += 2;
	}
	if (po->accuracy == 0)
		ft_space_string_x_little(str, po, 0);
	else
		ft_print_accuracy_x_l(str, po, 0, 0);
	free(str);
	return (1);
}

int		ft_print_help_p(t_print *po, char *str)
{
	if (po->accuracy == -1 && *str == '0' && po->width == 0)
	{
		ft_putstr("0x");
		po->returnsize += 2;
		return (0);
	}
	return (1);
}
