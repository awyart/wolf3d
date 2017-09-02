/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:54:59 by awyart            #+#    #+#             */
/*   Updated: 2017/09/02 19:23:13 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_putmap(t_env *env)
{
	int y;

	y = 0;
	while (y < env->y_max)
	{
		ft_putstr(env->map[y]);
		ft_putchar('\n');
		y++;
	}
}

void		ft_read(t_env *env, char *title)
{
	int y;
	int x;
	int fd;
	char *line;

	y = 0;
	x = 0;
	fd = open(title, O_RDONLY);
	env->map = (char**)malloc(sizeof(char*) * env->y_max);
	while (get_next_line(fd, &line) > 0)
	{
		env->map[y] = (char*)malloc(sizeof(char) * env->x_max);
		while (line[x] != '\0')
		{
			env->map[y][x] = line[x];
			x++;
		}
		x = 0;
		y++;
		if (line)
			free(line);
	}
	close(fd);
}

void ft_getsize(t_env *env, char *title)
{
	int fd;
	char *line;
	int x;
	int y;

	x = 0;
	y = 0;
	fd = open(title, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		x = ft_strlen(line);
		if (env->x_max < x)
			env->x_max = x;
	}
	env->y_max = y;
	close(fd);
}

int	ft_init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (0);
	env->win = mlx_new_window(env->mlx, WINX, WINY, "WOlF3D enfin presque");
	env->x = XI;
	env->y = YI;
	return (1);
}
