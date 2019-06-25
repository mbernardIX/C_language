/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:34 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_float(t_print *po, va_list ap, int sim, char *drobstr)
{
	long double		nbr;
	long long		celoe;
	char			*celstr;

	if (po->length == LLL)
		nbr = va_arg(ap, long double);
	nbr = va_arg(ap, double);
	celoe = nbr;
	celstr = ft_l_itoa(celoe);
	if (po->accuracy == 0)
		drobstr = ft_float_ac_0(nbr, &sim);
	if (po->accuracy > 0)
		drobstr = ft_float_ac_big(po, nbr, &sim);
	if (po->accuracy == -1)
	{
		drobstr = ft_float_ac_big(po, nbr, &sim);
		ft_roun(&celstr, &drobstr, sim, 0);
		free(drobstr);
		ft_float_ac_minus(po, celstr);
		free(celstr);
		return (1);
	}
	ft_roun(&celstr, &drobstr, sim, 0);
	print_space_float(po, celstr, drobstr);
	return (1);
}

void		print_space_float(t_print *po, char *celstr, char *drobstr)
{
	char	*strjoin;

	strjoin = NULL;
	if (po->minus == 0)
	{
		ft_space_string_dec(celstr, po, ft_strlen(drobstr) + 1);
		ft_putchar('.');
		ft_putstr(drobstr);
		free(drobstr);
		free(celstr);
	}
	else
	{
		celstr = ft_strjoin_free(celstr, ".", 1, 0);
		strjoin = ft_strjoin_free(celstr, drobstr, 1, 1);
		ft_space_string_dec(strjoin, po, 0);
		free(strjoin);
	}
}
