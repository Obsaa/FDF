/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 02:40:26 by oabdalha          #+#    #+#             */
/*   Updated: 2017/03/21 23:35:13 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*pointer;

	pointer = (unsigned char *)str;
	while (n > 0)
	{
		*pointer++ = (unsigned char)c;
		n--;
	}
	return (str);
}
