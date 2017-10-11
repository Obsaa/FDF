/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdalha <oabdalha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:40:22 by oabdalha          #+#    #+#             */
/*   Updated: 2017/10/03 04:45:16 by oabdalha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../libmlx/mlx.h"

# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# define WIN_X 2000
# define WIN_Y 1400
# define BUFF_SIZE 1500
# define ABS(Value) (Value < 0 ? -Value : Value)

typedef	struct	s_line
{
	float	cp1;
	float	cp2;
	int		dx;
	int		dy;
	int		x;
	int		y;
}				t_line;

typedef	struct	s_point
{
	int	x0;
	int	y0;
	int	x;
	int	y;
	int	z;
}				t_point;

typedef	struct	s_env
{
	void	*mlx;
	void	*win;
	char	*map;
	float	c1;
	float	c2;
	float	divpi;
	int		is_iso;
	float	piv;
	int		zoom;
	int		manz;
	int		tr;
	int		td;
	int		is_decr;
	int		zmax;
	int		zmin;
	int		xmax;
	int		xmin;
	int		ymax;
	int		ymin;
	t_point	**points_tab;
}				t_env;

void			ft_draw(void *mlx, void *win, int x, int y);
int				ft_fit_win(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);
int				loop_hook(t_env *e);
unsigned int	ft_strchri(char *stock, char c);
int				ft_set(char *tmp, char **stk, char **buffer);
int				get_next_line(const int fd, char **line);
int				calc_points(t_env *e);
int				put_map(t_env *e);
int				read_map(t_env *e);
unsigned int	get_color(int cp1, int cp2, int i, int delta);
void			display_comments(t_env *e);
t_point			**realloc_pts(t_point **pts, t_point *point);
t_point			*ft_realloc(t_point *old, t_point point, int nb_pts);

#endif
