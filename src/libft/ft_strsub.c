/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 05:11:45 by oabdalha          #+#    #+#             */
/*   Updated: 2017/03/21 01:08:38 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sbstr;

	if (s == NULL)
		return (NULL);
	sbstr = (char*)malloc(sizeof(char) * (len + 1));
	if (sbstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sbstr[i] = s[start + i];
		i++;
	}
	sbstr[i] = '\0';
	return (sbstr);
}
