/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 10:08:23 by dspider-          #+#    #+#             */
/*   Updated: 2019/02/12 11:54:36 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>

typedef struct	s_print
{
	short	flag;
	short	width;
	short	accur;
	int		mod;
	char	type;

	int		answer;
	short	space_one;
	short	is;
	char	p_or_n;
	short	nulls;
	short	space_end;

	short	len_bef;
	short	point;
	short	len_after;
}				t_print;

void			reading(char const *str, va_list args, t_print *list);
void			output(va_list argc, t_print *list);
int				ft_printf(const char *str, ...);
void			output_int(t_print *list, int n, char *str);
void			output_char(va_list argc, t_print *list);
void			output_str(char *str, t_print *list);
int				percent(const char *str);
int				type(char const *str, va_list argc, int len, t_print *list);
int				spez(char c);
void			output_eq_or_less_dec(unsigned long b, t_print *list,
		int w, int k);
void			output_more_dec(unsigned long b, t_print *list, int w, int k);
void			output_dif_int(long b, t_print *list);
void			result(t_print *list, char *str);
void			output_pointer(unsigned long b, t_print *list);

void			prepare_float(double b, t_print *list);

void			prep_t_print(t_print *list);
int				width_and_accur(char c, t_print *list, int m);
void			plus_strings(char *str, const char *dest, long i);
void			del_two_strings(char *man, int n, int k, t_print *list);
void			create(char *str, int k, t_print *list);

void			cout(char *s1, char *s2, t_print *list);
void			check_double(double f, t_print *list);

#endif
