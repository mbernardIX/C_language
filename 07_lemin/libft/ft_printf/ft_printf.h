/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <dspider-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:35:35 by dspider-          #+#    #+#             */
/*   Updated: 2019/06/07 14:54:56 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"
# define L 1
# define LL 2
# define H 3
# define HH 4
# define LLL 5

typedef struct		s_print
{
	int				infuncheck;
	int				accuracfree;
	int				i;
	int				returnsize;
	int				plus;
	int				minus;
	int				space;
	int				zero;
	int				sharp;
	int				width;
	int				accuracy;
	int				length;
}					t_print;

int					ft_printf(const char *format, ...);
int					ft_check_valid_param(char *str, int i, t_print *po);
t_print				*ft_struct_creat(t_print *po);
void				ft_clear_struct(t_print *po);
void				ft_parse_format(char *format, t_print *po, va_list ap);
void				ft_param(char *format, t_print *po, va_list ap);
void				ft_flags(char *format, t_print *po);
void				ft_width_param(char *format, t_print *po);
void				ft_accuracy(char *format, t_print *po);
void				ft_mod_length(char *format, t_print *po);
int					ft_type(char *format, t_print *po, va_list ap);
int					ft_print_procent(t_print *po);
int					ft_print_char(t_print *po, char sim);
int					ft_print_string(t_print *po, va_list ap);
void				ft_space_string(char *str, t_print *po);
char				*ft_accuracy_string(char *str, t_print *po, int sizestr);
int					ft_print_int(t_print *po, va_list ap);
char				*ft_add_d_mod_length(t_print *po, va_list ap,
						long long int n);
void				ft_space_string_dec(char *str, t_print *po, int sizestr);
void				hp_space_string_dec(char *str, t_print *po, int sizestr);
void				ft_check_space_int(char *str, t_print *po, int sizestr);
void				hp_check_space(char *str, t_print *po, int sizestr);
void				ft_print_accuracy_dec(char *str, t_print *po,
						int sizestr);
void				hp_print_accuracy_dec(char *str, t_print *po, int sizestr);
void				hp2_print_accuracy_dec(char *str, t_print *po, int sizestr);
void				ft_space_accuracy_dec(char *str, t_print *po, int sizestr);
int					ft_print_u(t_print *po, va_list ap);
char				*ft_add_u_mod_length(t_print *po, va_list ap,
						unsigned long long int n);
void				ft_space_string_u(char *str, t_print *po);
void				ft_print_accuracy_u(char *str, t_print *po,
						int sizestr, int saveacc);
void				hp_print_accuracy_u(char *str, t_print *po, int sizestr);
int					ft_print_o(t_print *po, va_list ap);
char				*ft_add_o_mod_length(t_print *po, va_list ap,
						unsigned long long int n);
int					ft_print_big_x(t_print *po, va_list ap);
char				*ft_add_b_x_mod_length(t_print *po, va_list ap,
						unsigned long long int n);
int					ft_print_little_x(t_print *po, va_list ap);
char				*ft_add_l_x_mod_length(t_print *po,
						va_list ap, unsigned long long int n);
void				ft_space_string_x_little(char *str,
						t_print *po, int sizestr);
void				hp_print_0x_little(t_print *po, char *str);
void				ft_space_string_x_big(char *str, t_print *po, int sizestr);
void				hp_print_0x_big(t_print *po, char *str);
void				ft_print_accuracy_x_b(char *str, t_print *po,
						int sizestr, int saveacc);
void				ft_print_accuracy_x_l(char *str, t_print *po,
						int sizestr, int saveacc);
void				hp2_print_accuracy_dec_x(char *str, t_print *po,
						int sizestr);
void				hp_norm_space_x(t_print *po, int sizestr);
int					ft_print_p(t_print *po, va_list ap);
int					ft_print_help_p(t_print *po, char *str);
char				*ft_add_l_p_mod_length(t_print *po, va_list ap,
						unsigned long long int n);
int					ft_print_float(t_print *po, va_list ap,
						int sim, char *drobstr);
void				print_space_float(t_print *po, char *celstr, char *drobstr);
char				*print_drobnoe(int nbr, long double drobnoe, int **sim);
char				*ft_float_ac_0(long double nbr, int *sim);
char				*ft_float_ac_big(t_print *po, long double nbr, int *sim);
void				ft_float_ac_minus(t_print *po, char *celstr);
void				ft_roun(char **celoe, char **drobnoe, int sim,
						long long i);
void				ft_roun_celoe(char **celoe, unsigned long long sizec,
						long long i);

#endif
