/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:34:00 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/11 21:20:01 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

void	infin(char *str, t_print *list)
{
	char	*p;

	p = NULL;
	if (list->accur < 0)
		list->accur = 6;
	else
		list->point = 0;
	p = ft_memset(ft_strnew(max(list->accur, 0)), '0', max(list->accur, 0));
	if (ft_strcmp(str, "0") == 0)
		cout(ft_strdup(str), p, list);
	if (list->flag % 11 == 0)
		list->flag /= 11;
	list->accur = 0;
	if (ft_strcmp(str, "inf") == 0)
		cout(ft_strdup(str), "", list);
	else if (ft_strcmp(str, "nan") == 0)
	{
		if (list->flag % 2 == 0)
			list->flag = 2;
		else
			list->flag = 1;
		cout(ft_strdup(str), "", list);
	}
	ft_strdel(p);
	ft_strdel(str);
}

void	nulls(double f, t_print *list)
{
	int					n;
	unsigned char		data[sizeof(double) + 1];
	unsigned long		i;
	char				k;

	ft_memcpy(data, &f, sizeof(double));
	i = -1;
	while (++i < sizeof(double))
	{
		n = 0;
		while (n < 8)
		{
			if (data[i] % 2 == 0)
				k = '0';
			else
				k = '1';
			data[i] = (data[i] - data[i] % 2) / 2;
			n++;
		}
	}
	list->answer++;
	if (k == '1')
		list->is = 1;
	list->point = 1;
	infin(ft_strdup("0"), list);
}

void	check_double(double f, t_print *list)
{
	char *str;

	str = NULL;
	if (isinf(f) == 1)
		str = ft_strdup("inf");
	if (isinf(f) == 1 && f < 0)
		list->is = 1;
	if (f == 0.0f)
	{
		nulls(f, list);
		str = ft_strdup("1");
	}
	if (isnan(f))
		str = ft_strdup("nan");
	if (str == NULL)
		prepare_float(f, list);
	else
		infin(ft_strdup(str), list);
	ft_strdel(str);
}
