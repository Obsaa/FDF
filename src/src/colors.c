/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 10:53:44 by oabdalha          #+#    #+#             */
/*   Updated: 2017/08/16 11:10:31 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

unsigned int	get_color_suite(int cp1, int cp2, int i, int delta)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				cursor;

	r = 255;
	b = 255;
	g = 255;
	cursor = cp1 + (float)(cp2 - cp1) * i / delta;
	if (cursor <= 191.25)
	{
		g = 4 * (float)(cursor - 191.25);
		b = 0;
	}
	else if (cursor > 191.5)
	{
		r = 4 * (float)(191.5 - cursor);
		b = 0;
	}
	color = (r << 16) + (g << 8) + b;
	return (color);
}

unsigned int	get_color(int cp1, int cp2, int i, int delta)
{
	unsigned int	color;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				cursor;

	r = 255;
	b = 255;
	g = 255;
	cursor = cp1 + (float)(cp2 - cp1) * i / delta;
	if (cursor <= 63.75)
		g = 4 * (float)(63.75 - cursor);
	else if (cursor <= 127.5)
	{
		b = 4 * (float)(127.5 - cursor);
		g = 0;
	}
	else
		return (get_color_suite(cp1, cp2, i, delta));
	color = (r << 16) + (g << 8) + b;
	return (color);
}
