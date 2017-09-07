/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:53:43 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 15:03:40 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_mvfw(t_env *env)
{
	int i;

	i = (int)(env->posy + MVSPEED * env->diry);
	if (env->map[i][(int)(env->posx + MVSPEED * env->dirx)] == 48)
	{
		env->posx += MVSPEED * env->dirx;
		env->posy += MVSPEED * env->diry;
	}
	ft_launch(env);
}

void	ft_mvbw(t_env *env)
{
	int i;

	i = (int)(env->posy - MVSPEED * env->diry);
	if (env->map[i][(int)(env->posx - MVSPEED * env->dirx)] == 48)
	{
		env->posx -= MVSPEED * env->dirx;
		env->posy -= MVSPEED * env->diry;
	}
	ft_launch(env);
}

void	ft_roright(t_env *env)
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

void	ft_roleft(t_env *env)
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
