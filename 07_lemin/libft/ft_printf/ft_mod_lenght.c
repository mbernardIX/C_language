/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_lenght.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:37 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_add_d_mod_length(t_print *po, va_list ap, long long int n)
{
	n = va_arg(ap, long long int);
	if (po->length == H)
		n = (short int)n;
	else if (po->length == HH)
		n = (char)n;
	else if (po->length == L)
		n = (long int)n;
	else if (po->length == LL)
		n = (long long int)n;
	else if (po->length == LLL)
		n = (long long)n;
	else
		n = (int)n;
	return (ft_ltoa_base(n, 10));
}

char	*ft_add_u_mod_length(t_print *po, va_list ap,
	unsigned long long int n)
{
	n = va_arg(ap, unsigned long long int);
	if (po->length == H)
		n = (unsigned short int)n;
	else if (po->length == HH)
		n = (unsigned char)n;
	else if (po->length == L)
		n = (unsigned long int)n;
	else if (po->length == LL)
		n = (unsigned long long int)n;
	else if (po->length == LLL)
		n = (unsigned long long)n;
	else
		n = (unsigned int)n;
	return (ft_utoa_base(n, 10));
}

char	*ft_add_o_mod_length(t_print *po, va_list ap,
	unsigned long long int n)
{
	n = va_arg(ap, unsigned long long int);
	if (po->length == H)
		n = (unsigned short int)n;
	else if (po->length == HH)
		n = (unsigned char)n;
	else if (po->length == L)
		n = (unsigned long int)n;
	else if (po->length == LL)
		n = (unsigned long long int)n;
	else if (po->length == LLL)
		n = (unsigned long long)n;
	else
		n = (unsigned int)n;
	return (ft_utoa_base(n, 8));
}

char	*ft_add_b_x_mod_length(t_print *po, va_list ap,
	unsigned long long int n)
{
	n = va_arg(ap, unsigned long long int);
	if (po->length == H)
		n = (unsigned short int)n;
	else if (po->length == HH)
		n = (unsigned char)n;
	else if (po->length == L)
		n = (unsigned long int)n;
	else if (po->length == LL)
		n = (unsigned long long int)n;
	else if (po->length == LLL)
		n = (unsigned long long)n;
	else
		n = (unsigned int)n;
	return (ft_utoa_base(n, 16));
}

char	*ft_add_l_x_mod_length(t_print *po, va_list ap,
	unsigned long long int n)
{
	n = va_arg(ap, unsigned long long int);
	if (po->length == H)
		n = (unsigned short int)n;
	else if (po->length == HH)
		n = (unsigned char)n;
	else if (po->length == L)
		n = (unsigned long int)n;
	else if (po->length == LL)
		n = (unsigned long long int)n;
	else if (po->length == LLL)
		n = (unsigned long long)n;
	else
		n = (unsigned int)n;
	return (ft_utoa_base_little(n, 16));
}
