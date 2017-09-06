/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 18:54:59 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 17:09:02 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_putmap(t_env *env)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < env->y_max + 2)
	{
		while (x < env->x_max + 2)
		{
			if (env->map[y][x] > 48)
				ft_putchar('*');
			else
				ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

void		ft_read(t_env *env, char *title)
{
	int y;
	int x;
	int fd;
	char *line;

	y = 1;
	x = -1;
	fd = open(title, O_RDONLY);
	env->map = (char**)malloc(sizeof(char*) * (env->y_max + 3));
	env->map[0] = (char*)malloc(sizeof(char) * (env->x_max + 3));
	while (++x <= env->x_max + 1)
		env->map[0][x] = 49;
	env->map[0][x] = '\0';
	x = 0;
	while (get_next_line(fd, &line) > 0)
	{
		env->map[y] = (char*)malloc(sizeof(char) * (env->x_max + 3));
		env->map[y][0] = 49;
		while (line[x] != '\0')
		{
			env->map[y][x + 1] = line[x];
			x++;
		}
		while (x <= env->x_max + 1)
		{
			env->map[y][x] = 49;
			x++;
		}
		env->map[y][x] = '\0';
		x = 0;
		y++;
		if (line)
			free(line);
	}
	env->map[y] = (char*)malloc(sizeof(char) * (env->x_max + 3));
	x = -1;
	while (++x <= env->x_max + 1)
		env->map[y][x] = 49;
	env->map[y][x] = '\0';
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
	env->x_max = 0;
	fd = open(title, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		y++;
		x = ft_strlen(line);
		if (env->x_max < x)
			env->x_max = x;
	}
	env->y_max = y;
	//ft_putnbr(env->y_max);
	close(fd);
}

int	ft_init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (0);
	env->win = mlx_new_window(env->mlx, WINX, WINY, "WOlF3D enfin presque");
	env->posX = posXI;
	env->posY = posYI;
	env->dirX = dirXI;
	env->dirY = dirYI;
	env->lay = 0;
	env->etoile = 0;
	env->planeX = planeXI;
	env->planeY = planeYI;
	return (1);
}
