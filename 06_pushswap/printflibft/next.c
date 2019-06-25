/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:12:36 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/12 11:54:24 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	output_char(va_list argc, t_print *list)
{
	long	b;

	b = va_arg(argc, long);
	list->answer += 1;
	if (list->flag % 2 != 0)
		while (list->width - 1 > 0)
		{
			ft_putchar(' ');
			list->answer += 1;
			list->width -= 1;
		}
	ft_putchar(b);
	if (list->flag % 2 == 0)
		while (list->width - 1 > 0)
		{
			ft_putchar(' ');
			list->answer += 1;
			list->width -= 1;
		}
}

void	output_str(char *str, t_print *list)
{
	int	n;
	int	i;

	i = 0;
	if (str == NULL)
		str = "(null)";
	n = ft_strlen(str);
	if (n > list->accur && list->accur > -1)
		n = list->accur;
	if (list->flag % 2 != 0)
	{
		if (list->flag % 11 == 0)
			ft_putchar_n('0', list->width - n);
		else
			ft_putchar_n(' ', list->width - n);
	}
	list->answer += n + max(list->width - n, 0);
	while (i++ < n)
		ft_putchar(str[i - 1]);
	if (list->flag % 2 == 0)
		ft_putchar_n(' ', list->width - n);
}

void	output_more_dec(unsigned long b, t_print *list, int w, int k)
{
	int				i;
	char			*str;

	str = NULL;
	i = 10;
	if (list->type == 'x' || list->type == 'X')
		i = 16;
	if (list->type == 'X')
		k = -32;
	if (i == 16 && list->flag % 7 == 0 && b != 0)
		w = 2;
	if (list->mod == 0)
		b = (unsigned int)b;
	else if (list->mod == 'h')
		b = (unsigned short int)b;
	else if (list->mod == 1001 * 'h')
		b = (unsigned char)b;
	else if (list->mod == 1001 * 'l' || list->mod == 'l')
		b = (unsigned long)b;
	if (b == 0 && list->accur == 0)
		str = ft_strnew(0);
	else
		str = ft_itoa_base(b, i, k);
	output_int(list, w, str);
	ft_strdel(str);
}

void	output_pointer(unsigned long b, t_print *list)
{
	char	*str;

	str = NULL;
	if (b == 0 && list->accur == 0)
		output_int(list, 2, str);
	else if (b == 0)
	{
		list->accur += 2;
		output_int(list, 2, "0");
	}
	else
	{
		str = ft_itoa_base(b, 16, 0);
		output_int(list, 2, str);
	}
	ft_strdel(str);
}
