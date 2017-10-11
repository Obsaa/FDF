/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 05:11:45 by oabdalha          #+#    #+#             */
/*   Updated: 2017/03/21 01:08:38 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*vai;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		vai = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = vai;
	}
	*alst = NULL;
	return ;
}
