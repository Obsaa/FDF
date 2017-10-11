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

int		read_line(t_env *e, char **axe_y, int i)
{
	char	**axe_x;
	t_point point;
	int		j;

	if ((axe_x = ft_strsplit(axe_y[i], ' ')) == NULL)
		return (-1);
	j = 0;
	while (axe_x[j] != 0)
	{
		point.x0 = j;
		point.y0 = i;
		point.x = 0;
		point.y = 0;
		point.z = ft_atoi(axe_x[j]);
		e->points_tab[i] = ft_realloc(e->points_tab[i], point, j);
		j++;
	}
	ft_strdel(axe_y);
	if (!(e->points_tab = realloc_pts(e->points_tab, e->points_tab[i])))
		return (-1);
	return (0);
}

int		read_map(t_env *e)
{
	char	**axe_y;
	int		i;

	i = 0;
	if ((axe_y = ft_strsplit(e->map, '\n')) == NULL)
		return (-1);
	if (!(e->points_tab = (t_point**)malloc(sizeof(t_point*))))
		return (-1);
	while (axe_y[i] != 0)
	{
		read_line(e, axe_y, i);
		i++;
	}
	e->points_tab[i] = NULL;
	ft_strdel(axe_y);
	return (0);
}

void	init_env(t_env *e, char *map)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_X, WIN_Y, "fDf42");
	e->map = map;
	e->divpi = M_PI / 6;
	e->c1 = (float)sin(e->divpi);
	e->c2 = (float)cos(e->divpi);
	e->is_iso = 1;
	e->tr = 1000;
	e->td = 100;
	e->piv = 1;
	e->manz = 10;
	e->zmax = 0;
	e->zmin = 0;
	e->ymax = 0;
	e->ymin = 0;
	e->xmax = 0;
	e->xmin = 0;
	e->zoom = 20;
}

int		call_mlx(char *map)
{
	t_env	e;

	init_env(&e, map);
	if (read_map(&e) != -1 && calc_points(&e) != -1)
	{
		while (e.zoom > 1 && !ft_fit_win(&e))
		{
			e.ymax = 0;
			e.ymin = 0;
			e.xmax = 0;
			e.xmin = 0;
			e.zoom /= 2;
			calc_points(&e);
		}
		mlx_expose_hook(e.win, put_map, &e);
	}
	mlx_key_hook(e.win, key_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	loop_hook(&e);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*buffer;
	char	*tmp;
	char	*map;
	int		ret;

	if (ac != 2)
		ft_putstr("Invalid argument count");
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_putstr("Invalid file type");
	if ((map = ft_strnew(BUFF_SIZE)) == NULL)
		ft_putstr("Invalid buff size");
	if ((buffer = ft_strnew(BUFF_SIZE)) == NULL)
		ft_putstr("Invalid buff size");
	ret = 1;
	while ((ret = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[ret] = '\0';
		if (ret == -1 || !(tmp = ft_strjoin(map, buffer))
			|| ft_set(tmp, &map, &buffer) == -1)
			return (0);
	}
	ft_strdel(&buffer);
	call_mlx(map);
}
