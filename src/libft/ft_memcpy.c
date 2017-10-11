/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 23:14:57 by oabdalha          #+#    #+#             */
/*   Updated: 2017/03/21 01:13:37 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*pointer;
	char	*pointer2;

	pointer = dst;
	pointer2 = (char *)src;
	i = 0;
	while (i < n)
	{
		*(pointer + i) = *(pointer2 + i);
		i++;
	}
	return (dst);
}
