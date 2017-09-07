/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:53:43 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 17:58:06 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static int	ft_check_pos(t_env *env, double k, double l)
{
	double	x;
	double	y;
	int		i;
	int		j;

	x = env->posx;
	y = env->posy;
	i = (env->posy + l);
	j = (env->posx + k);
	while ((int)x != j && (int)y != i)
	{
		x += MVSPEED * env->dirx / 100;
		y += MVSPEED * env->diry / 100;
		if (env->map[(int)y][(int)x] != 48)
			return (0);
	}
	return (1);
}

void		ft_mvfw(t_env *env)
{
	double i;
	double j;

	i = (env->posy + MVSPEED * env->diry);
	j = (env->posx + MVSPEED * env->dirx);
	if (env->map[(int)i][(int)j] == 48 &&
		ft_check_pos(env, MVSPEED * env->dirx, MVSPEED * env->dirx))
	{
		env->posx += MVSPEED * env->dirx;
		env->posy += MVSPEED * env->diry;
	}
	ft_launch(env);
}

void		ft_mvbw(t_env *env)
{
	double i;
	double j;

	i = (env->posy - MVSPEED * env->diry);
	j = (env->posx - MVSPEED * env->dirx);
	if (env->map[(int)i][(int)j] == 48 &&
		ft_check_pos(env, -MVSPEED * env->dirx, -MVSPEED * env->diry))
	{
		env->posx -= MVSPEED * env->dirx;
		env->posy -= MVSPEED * env->diry;
	}
	ft_launch(env);
}

void		ft_roright(t_env *env)
{
	double	dx;
	double	dy;
	double	px;
	double	py;
	double	tmp;

	dx = env->dirx;
	dy = env->diry;
	px = env->planex;
	py = env->planey;
	env->dirx = cos(ANGLE) * env->dirx - sin(ANGLE) * env->diry;
	env->diry = sin(ANGLE) * env->dirx + cos(ANGLE) * env->diry;
	env->dirx *= FACTOR / sqrt(env->dirx * env->dirx + env->diry * env->diry);
	env->diry *= FACTOR / sqrt(env->dirx * env->dirx + env->diry * env->diry);
	tmp = sqrt(env->diry * env->diry + env->dirx * env->dirx);
	env->planey = env->dirx / (tmp);
	env->planex = -env->diry * env->planey / env->dirx;
	ft_launch(env);
}

void		ft_roleft(t_env *env)
{
	double	dx;
	double	dy;
	double	px;
	double	py;
	double	tmp;

	dx = env->dirx;
	dy = env->diry;
	px = env->planex;
	py = env->planey;
	env->dirx = cos(-ANGLE) * env->dirx - sin(-ANGLE) * env->diry;
	env->diry = sin(-ANGLE) * env->dirx + cos(-ANGLE) * env->diry;
	env->dirx *= FACTOR / sqrt(env->dirx * env->dirx + env->diry * env->diry);
	env->diry *= FACTOR / sqrt(env->dirx * env->dirx + env->diry * env->diry);
	tmp = sqrt(env->diry * env->diry + env->dirx * env->dirx);
	env->planey = env->dirx / (tmp);
	env->planex = -env->diry * env->planey / env->dirx;
	ft_launch(env);
}
