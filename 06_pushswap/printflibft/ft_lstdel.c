/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspider- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:30:01 by dspider-          #+#    #+#             */
/*   Updated: 2018/12/09 17:29:22 by dspider-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *s;

	if (!alst && !del)
		return ;
	while (*alst)
	{
		s = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&s, del);
	}
}
