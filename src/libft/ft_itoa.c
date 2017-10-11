/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 05:11:45 by oabdalha          #+#    #+#             */
/*   Updated: 2017/03/21 01:08:38 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*ret;
	int			temp_n;
	size_t		size_ret;
	char		sign;

	sign = (n < 0) ? -1 : 1;
	size_ret = 2 + (n < 0);
	temp_n = n;
	while ((temp_n = temp_n / 10))
		size_ret++;
	if ((ret = (char *)malloc(sizeof(char) * size_ret--)) == NULL)
		return (NULL);
	ret[size_ret--] = '\0';
	ret[size_ret--] = sign * (n % 10) + '0';
	while ((n = n / 10))
		ret[size_ret--] = sign * (n % 10) + '0';
	if (sign < 0)
		ret[size_ret] = '-';
	return (ret);
}
