/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 11:30:54 by oabdalha          #+#    #+#             */
/*   Updated: 2017/07/06 11:10:59 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_point			**realloc_pts(t_point **pts, t_point *point)
{
	unsigned int	i;
	unsigned int	nb_pts;
	t_point			**pts_tmp;

	nb_pts = 0;
	while (pts[nb_pts])
		nb_pts++;
	if (!(pts_tmp = (t_point**)malloc(sizeof(t_point*) * (nb_pts + 2))))
		return (NULL);
	i = -1;
	while (++i < nb_pts)
		pts_tmp[i] = pts[i];
	free(pts);
	pts_tmp[i] = point;
	pts_tmp[i + 1] = NULL;
	return (pts_tmp);
}

t_point			*ft_realloc(t_point *old, t_point point, int nb_pts)
{
	t_point			*new;
	int				i;

	if ((new = (t_point*)malloc(sizeof(t_point) * (nb_pts + 2))) == NULL)
		return (NULL);
	i = -1;
	while (++i < nb_pts)
		new[i] = old[i];
	new[i] = point;
	ft_bzero((new + i + 1), sizeof(t_point));
	return (new);
}

static int		failed(char **buffer, char **stock)
{
	ft_strdel(buffer);
	ft_strdel(stock);
	return (-1);
}

int				ft_set(char *tmp, char **stk, char **buffer)
{
	ft_strdel(stk);
	if (!(*stk = ft_strdup(tmp)))
		return (failed(buffer, stk));
	ft_strdel(&tmp);
	return (1);
}
