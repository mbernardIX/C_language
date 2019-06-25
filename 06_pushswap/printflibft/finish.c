/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 15:34:58 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/11 19:23:52 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	lucky_boy(char *s1, char *s2, t_print *list)
{
	list->answer += list->space_one + list->is + list->nulls + list->len_bef
		+ list->len_after * list->point + list->point + list->space_end
		+ max(list->accur - list->len_after, 0);
	while (list->space_one-- > 0)
		ft_putchar(' ');
	if (list->is == 1)
		ft_putchar(list->p_or_n);
	while (list->nulls-- > 0)
		ft_putchar('0');
	while (*s1)
		ft_putchar(*s1++);
	if (list->point == 1)
		ft_putchar('.');
	if (list->point == 1)
		while (*s2)
			ft_putchar(*s2++);
	while (list->accur-- - list->len_after > 0)
		ft_putchar('0');
	while (list->space_end-- > 0)
		ft_putchar(' ');
}

void	cout(char *s1, char *s2, t_print *list)
{
	list->len_bef = ft_strlen(s1);
	if (list->point == 1)
		list->len_after = ft_strlen(s2);
	if (list->is == 1)
		list->p_or_n = '-';
	else if (list->flag % 3 == 0 && list->is++ == 0)
		list->p_or_n = '+';
	else if (list->flag % 5 == 0 && list->is++ == 0)
		list->p_or_n = ' ';
	if (list->flag % 2 != 0)
	{
		if (list->flag % 11 == 0)
			list->nulls = max(list->width - max(list->len_after, list->accur)
					- list->len_bef - list->point - list->is, 0);
		else
			list->space_one = max(-list->is - max(list->accur, list->len_after)
					- list->len_bef - list->point + list->width, 0);
	}
	else
	{
		list->space_end = max(list->width - list->len_bef -
				max(list->len_after, list->accur) - list->point - list->is, 0);
	}
	lucky_boy(s1, s2, list);
	ft_strdel(s1);
}

void	create(char *total, int k, t_print *list)
{
	char	*s1;
	char	*str;
	int		i;

	s1 = NULL;
	str = ft_strnew(k + list->accur + 2);
	str = ft_strncpy(str, total, k + list->accur + 1);
	str = rev_str(str, k + list->accur + 1);
	plus_strings(str, "4", 0);
	str = rev_str(str, k + list->accur + 1);
	str[k + list->accur] = '\0';
	i = -1;
	while (++i < k)
		if (str[i] != '0')
		{
			s1 = ft_strncpy(ft_strnew(k - i), &str[i], k - i);
			break ;
		}
	if (s1 == NULL)
	{
		s1 = ft_strnew(1);
		s1[0] = '0';
	}
	cout(s1, &str[k], list);
	ft_strdel(str);
}
