/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:20:06 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/09 17:22:08 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	size_t	n;

	if (!alst && !del)
		return ;
	n = (*alst)->content_size;
	del((*alst)->content, n);
	free(*alst);
	*alst = NULL;
}
