/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arr_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrika <rrika@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 10:13:28 by mbernard          #+#    #+#             */
/*   Updated: 2019/06/03 15:32:35 by rrika            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_arr_free(int **arr, int row)
{
	int		i;

	i = 0;
	if (arr == 0)
		return ;
	while (i < row)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}