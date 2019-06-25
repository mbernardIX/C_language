/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_part.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 10:24:09 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/11 19:50:50 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	plus_strings(char *str, const char *dest, long i)
{
	while (str[i] && dest[i])
	{
		if (str[i] + dest[i] - 96 >= 10)
		{
			if (ft_isdigit(str[i + 1]) == 1)
				str[i + 1] += 1;
			else
				str[i + 1] = '1';
			str[i] -= 10;
		}
		str[i] = str[i] + dest[i] - 48;
		i++;
	}
	i--;
	while (str[++i])
		if (str[i] - 48 >= 10)
		{
			if (ft_isdigit(str[i + 1]) == 1)
				str[i + 1] += 1;
			else
				str[i + 1] = '1';
			str[i] = str[i] - 10;
		}
		else
			break ;
}

void	del_two_strings(char *man, int n, int k, t_print *list)
{
	char	*end;
	long	i;

	end = ft_strnew(210);
	ft_memmove(end, man, ft_strlen(man));
	while (n-- > 0)
	{
		i = -1;
		while (end[++i])
		{
			if ((end[i] - 48) % 2 == 0)
				end[i] = (end[i] - 48) / 2 + 48;
			else
			{
				end[i] = (end[i] - 48 - 1) / 2 + 48;
				if (ft_isdigit(end[i + 1]) == 1)
					end[i + 1] += 10;
				else
					end[i + 1] = '0' + 10;
			}
		}
	}
	create(end, k, list);
	ft_strdel(end);
}

void	mantissa_float(char *man, char *str, int n, t_print *list)
{
	char	*tmp;

	tmp = NULL;
	man[0] = '1';
	while (*str || n > 0)
	{
		if (*str != ' ')
		{
			tmp = ft_strdup(man);
			plus_strings(man, tmp, 0);
			if (*str == '1')
				plus_strings(man, "1", 0);
			ft_strdel(tmp);
		}
		if (*str == '\0')
			n--;
		else
			str++;
	}
	man = rev_str(man, ft_strlen(man));
	if (n < 0)
		del_two_strings(man, -n, ft_strlen(man), list);
	else
		create(man, ft_strlen(man), list);
	ft_strdel(man);
}

void	power_float(char *str, t_print *list)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	if (*str == '1')
	{
		list->is = 1;
		list->p_or_n = '-';
	}
	str++;
	while (i++ <= 11)
	{
		if (*str != ' ')
			n = n * 2 + (*str - 48);
		str++;
	}
	n -= 1023;
	if (list->accur == -1)
		list->accur = 6;
	if (list->accur != 0)
		list->point = 1;
	mantissa_float(ft_strnew(200), str, n - 52, list);
}

void	prepare_float(double f, t_print *list)
{
	int					n;
	unsigned char		data[sizeof(double) + 1];
	unsigned long		i;
	char				*str;

	str = ft_strnew(71);
	ft_memcpy(data, &f, sizeof(double));
	n = 0;
	i = -1;
	while (++i < sizeof(double))
	{
		if (n != 0)
			str[n++] = ' ';
		while (n - 9 * i <= 7)
		{
			if (data[i] % 2 == 0)
				str[n++] = '0';
			else
				str[n++] = '1';
			data[i] = (data[i] - data[i] % 2) / 2;
		}
	}
	str = rev_str(str, n);
	power_float(str, list);
	ft_strdel(str);
}
