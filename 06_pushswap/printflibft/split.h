/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:14:19 by dspider-          #+#    #+#             */
/*   Updated: 2019/03/02 10:14:33 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

# include "libft.h"

int		ft_calc_letters(char const *s, char c);
char	**ft_strsplit(char const *s, char c);
char	**ft_free_array(char **str, int i);
int		ft_calc_words(char const *s, char c);

#endif
