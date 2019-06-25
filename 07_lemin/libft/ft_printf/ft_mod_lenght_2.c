/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod_lenght_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:55:22 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_add_l_p_mod_length(t_print *po, va_list ap,
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
		n = (unsigned long int)n;
	return (ft_utoa_base_little(n, 16));
}
