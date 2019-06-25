/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/27 14:51:25 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/12 11:55:25 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	result(t_print *list, char *str)
{
	while (list->space_one-- > 0)
		ft_putchar(' ');
	if (list->is == 1)
		ft_putchar(list->p_or_n);
	if (list->type == 'p' ||
			(list->flag % 7 == 0 && *str != '\0' && *str != '0'))
	{
		if (list->type == 'x' || list->type == 'p')
			ft_putstr("0x");
		else if (list->type == 'X')
			ft_putstr("0X");
	}
	if (list->type == 'o' && list->flag % 7 == 0)
		ft_putchar('0');
	while (list->nulls-- > 0)
		ft_putchar('0');
	if (str != NULL)
		ft_putstr(str);
	while (list->space_end-- > 0)
		ft_putchar(' ');
}

void	output_int(t_print *list, int n, char *str)
{
	n += ft_strlen(str);
	list->nulls = max(list->accur - n, 0);
	if (list->flag % 2 != 0)
	{
		if (list->flag % 11 == 0 && list->accur < 0)
			list->nulls = max(list->width - n - list->is - list->nulls,
					list->nulls);
		else
			list->space_one = max(list->width - n - list->is - list->nulls, 0);
	}
	else
	{
		list->space_end = max(list->width - n - list->is - list->nulls, 0);
	}
	list->answer += list->space_one + list->is + list->nulls +
		n + list->space_end;
	result(list, str);
}

void	output_dif_int(long b, t_print *list)
{
	char	*str;

	str = NULL;
	if (list->mod == 0)
		b = (int)b;
	else if (list->mod == 'h')
		b = (short int)b;
	else if (list->mod == 1001 * 'l' || list->mod == 'l')
		b = (long)b;
	else if (list->mod == 1001 * 'h')
		b = (char)b;
	if (b != 0 || list->accur != 0 || list->flag % 3 == 0)
		str = ft_itoa(b);
	if (b < 0 && list->is++ == 0)
		list->p_or_n = '-';
	else if (list->flag % 3 == 0 && list->is++ == 0)
		list->p_or_n = '+';
	else if (list->flag % 5 == 0 && list->is++ == 0)
		list->p_or_n = ' ';
	if (b < 0)
		output_int(list, 0, str + 1);
	else
		output_int(list, 0, str);
	ft_strdel(str);
}

void	output_eq_or_less_dec(unsigned long b, t_print *list, int w, int k)
{
	int				i;
	char			*str;

	str = NULL;
	i = 10;
	if (list->type == 'o' || list->type == 'O')
		i = 8;
	if (i == 8 && list->flag % 7 == 0)
		w = 1;
	if (list->mod == 0)
		b = (unsigned int)b;
	else if (list->mod == 1001 * 'h')
		b = (unsigned char)b;
	else if (list->mod == 'h')
		b = (unsigned short)b;
	else if (list->mod == 1001 * 'l' || list->mod == 'l')
		b = (unsigned long)b;
	if (b == 0 && list->accur == 0)
		str = ft_strnew(0);
	else
		str = ft_itoa_base(b, i, k);
	output_int(list, w, str);
	ft_strdel(str);
}

void	output(va_list argc, t_print *list)
{
	long double	g;

	if (list->type == 'd' || list->type == 'i')
		output_dif_int(va_arg(argc, long), list);
	else if (list->type == 'o' || list->type == 'u' ||
			list->type == 'O' || list->type == 'U')
		output_eq_or_less_dec(va_arg(argc, unsigned long), list, 0, 0);
	else if (list->type == 'x' || list->type == 'X')
		output_more_dec(va_arg(argc, unsigned long), list, 0, 0);
	else if (list->type == 'c')
		output_char(argc, list);
	else if (list->type == 's')
		output_str(va_arg(argc, char *), list);
	else if ((list->type == 'f' || list->type == 'F') && list->mod == 'L')
	{
		g = va_arg(argc, long double);
		check_double((double)g, list);
	}
	else if (list->type == 'f' || list->type == 'F')
		check_double(va_arg(argc, double), list);
	else if (list->type == 'p')
		output_pointer(va_arg(argc, unsigned long), list);
	else
		output_int(list, 0, "%");
}
