/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 12:56:06 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/12 11:56:04 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

int		spez(char c)
{
	if (c == 'i' || c == 'd' || c == 'u' || c == 'o' || c == 'x' || c == 'X' ||
			c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G'
			|| c == 'a' || c == 'A' || c == 'c' || c == 's' || c == 'S' ||
			c == 'p' || c == 'n' || c == 'O' || c == 'U')
		return (c);
	if (c == '%')
		return ('%');
	return ('0');
}

int		width_and_accur(char c, t_print *list, int m)
{
	if (c == '0' && list->width == 0 && list->accur == -1 && m == 0)
	{
		list->flag *= 11;
		m = -1;
	}
	else if (c == '.')
	{
		list->accur = 0;
		m = 1;
	}
	else if (c <= '9' && c >= '0' && (m == -1 || m == 0))
	{
		list->width = list->width * 10 + c - 48;
		m = -1;
	}
	else if (c <= '9' && c >= '0' && m == 1)
		list->accur = list->accur * 10 + c - 48;
	return (m);
}

int		type(char const *str, va_list argc, int len, t_print *list)
{
	int	m;

	m = 0;
	while ((list->type = spez(*(str + len))) == '0')
	{
		if (str[len] == '-' && list->flag % 2 != 0)
			list->flag *= 2;
		else if (str[len] == '+' && list->flag % 3 != 0)
			list->flag *= 3;
		else if (str[len] == ' ' && list->flag % 5 != 0)
			list->flag *= 5;
		else if (str[len] == '#' && list->flag % 7 != 0)
			list->flag *= 7;
		else if ((str[len] == 'h' && str[len + 1] == 'h') ||
				(str[len] == 'l' && str[1 + len] == 'l'))
			list->mod = str[++len] * 1001;
		else if (str[len] == 'h' || str[len] == 'l' || str[len] == 'L')
			list->mod = str[len];
		else
			m = width_and_accur(str[len], list, m);
		len++;
	}
	output(argc, list);
	return (len);
}

int		percent(const char *str)
{
	int j;

	j = 1;
	while (*(str + j) && spez(*(str + j)) == '0')
		j++;
	if (*(str + j) == '\0')
		return (-2);
	return (-1);
}

void	reading(char const *str, va_list args, t_print *list)
{
	int		t;

	while (*str)
	{
		t = 0;
		if (*str == '%' && (t = percent(str)) == -1)
		{
			prep_t_print(list);
			str = str + type(str, args, 1, list);
		}
		else
		{
			if (t == -2)
				return ;
			list->answer += 1;
			ft_putchar(*str);
		}
		str++;
	}
}
