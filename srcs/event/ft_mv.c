/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:53:43 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 18:54:06 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_mvfw(t_env *env)
{
	if (env->map[(int)(env->posY + MVSPEED * env->dirY)][(int)(env->posX + MVSPEED * env->dirX)] == 48)
	{
		env->posX += MVSPEED * env->dirX;
		env->posY += MVSPEED * env->dirY;
	}
	ft_launch(env);
}

void	ft_mvbw(t_env *env)
{
	if (env->map[(int)(env->posY - MVSPEED * env->dirY)][(int)(env->posX - MVSPEED * env->dirX)] == 48)
	{
		env->posX -= MVSPEED * env->dirX;
		env->posY -= MVSPEED * env->dirY;
	}
	ft_launch(env);
}

void	ft_roright(t_env *env)
{
	double dx;
	double dy;
	double px;
	double py;

	dx = env->dirX;
	dy = env->dirY;
	px = env->planeX;
	py = env->planeY;
	env->dirX = cos(ANGLE) * env->dirX - sin(ANGLE) * env->dirY;
	env->dirY = sin(ANGLE) * env->dirX + cos(ANGLE) * env->dirY;
	env->dirX *= FACTOR / sqrt(env->dirX * env->dirX + env->dirY * env->dirY); 
	env->dirY *= FACTOR / sqrt(env->dirX * env->dirX + env->dirY * env->dirY);
	env->planeY = env->dirX / (sqrt(env->dirY * env->dirY + env->dirX * env->dirX));
	env->planeX = -env->dirY * env->planeY /env->dirX ;
	ft_launch(env);
}

void	ft_roleft(t_env *env)
{
	double dx;
	double dy;
	double px;
	double py;

	dx = env->dirX;
	dy = env->dirY;
	px = env->planeX;
	py = env->planeY;
	env->dirX = cos(-ANGLE) * env->dirX - sin(-ANGLE) * env->dirY;
	env->dirY = sin(-ANGLE) * env->dirX + cos(-ANGLE) * env->dirY;
	env->dirX *= FACTOR / sqrt(env->dirX * env->dirX + env->dirY * env->dirY); 
	env->dirY *= FACTOR / sqrt(env->dirX * env->dirX + env->dirY * env->dirY);
	env->planeY = env->dirX / (sqrt(env->dirY * env->dirY + env->dirX * env->dirX));
	env->planeX = -env->dirY * env->planeY /env->dirX ;
	ft_launch(env);
}