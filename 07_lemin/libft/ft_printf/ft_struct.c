/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:54:50 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_clear_struct(t_print *po)
{
	po->minus = 0;
	po->plus = 0;
	po->sharp = 0;
	po->space = 0;
	po->zero = 0;
	po->width = 0;
	po->accuracy = 0;
	po->accuracfree = 0;
	po->infuncheck = 0;
	po->length = 0;
}

t_print			*ft_struct_creat(t_print *po)
{
	if (!(po = (t_print*)malloc(sizeof(t_print))))
		return (NULL);
	po->returnsize = 0;
	po->length = 0;
	po->minus = 0;
	po->plus = 0;
	po->sharp = 0;
	po->space = 0;
	po->zero = 0;
	po->width = 0;
	po->accuracy = 0;
	po->accuracfree = 0;
	po->infuncheck = 0;
	po->i = 0;
	return (po);
}
