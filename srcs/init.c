/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:54:59 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 18:07:28 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_assignd(t_env *env, char *line, int *x, int *y)
{
	if (!(env->map[(*y)] = (char*)malloc(sizeof(char) * (env->x_max + 3))))
		ft_errmalloc();
	env->map[(*y)][0] = 49;
	while (line[*x] != '\0')
	{
		env->map[(*y)][*x + 1] = line[*x];
		(*x)++;
	}
	while (*x <= env->x_max + 1)
	{
		env->map[(*y)][*x] = 49;
		(*x)++;
	}
	env->map[(*y)][*x] = '\0';
	*x = 0;
	(*y)++;
	if (line)
	{
		free(line);
		line = NULL;
	}
}

void		ft_read(t_env *env, char *title)
{
	int		y;
	int		x;
	int		fd;
	char	*line;

	y = 1;
	x = -1;
	fd = open(title, O_RDONLY);
	if (!(env->map = (char**)malloc(sizeof(char*) * (env->y_max + 3))))
		ft_errmalloc();
	if (!(env->map[0] = (char*)malloc(sizeof(char) * (env->x_max + 3))))
		ft_errmalloc();
	while (++x <= env->x_max + 1)
		env->map[0][x] = 49;
	env->map[0][x] = '\0';
	x = 0;
	while (get_next_line(fd, &line) > 0)
		ft_assignd(env, line, &x, &y);
	if (!(env->map[y] = (char*)malloc(sizeof(char) * (env->x_max + 3))))
		ft_errmalloc();
	x = -1;
	while (++x <= env->x_max + 1)
		env->map[y][x] = 49;
	env->map[y][x] = '\0';
	if (line)
	{
		free(line);
		line = NULL;
	}
	close(fd);
}

void		ft_getsize(t_env *env, char *title)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	x = 0;
	y = 0;
	env->x_max = 0;
	if (!(fd = open(title, O_RDONLY)))
	{
		ft_putstr("carte illisible\n");
		exit(0);
	}
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		x = ft_strlen(line);
		if (env->x_max < x)
			env->x_max = x;
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	if (line)
		free(line);
	env->y_max = y;
	close(fd);
}

int			ft_init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (0);
	env->win = mlx_new_window(env->mlx, WINX, WINY, "WOlF3D enfin presque");
	env->posx = POSXI;
	env->posy = POSYI;
	env->dirx = DIRXI;
	env->diry = DIRYI;
	env->lay = 0;
	env->etoile = 0;
	env->planex = PLANEXI;
	env->planey = PLANEYI;
	return (1);
}
