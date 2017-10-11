/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 05:11:45 by oabdalha          #+#    #+#             */
/*   Updated: 2017/03/21 01:08:38 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	end;

	i = 0;
	while (dst[i] && i < size)
		i++;
	end = i;
	if (size == 0)
		return (size + ft_strlen(src));
	while (src[i - end] && i < size - 1)
	{
		dst[i] = src[i - end];
		i++;
	}
	if (end < size)
		dst[i] = '\0';
	return (end + ft_strlen(src));
}
