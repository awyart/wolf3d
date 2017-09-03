/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:53:43 by awyart            #+#    #+#             */
/*   Updated: 2017/09/03 18:11:42 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
# define MVSPEED 0.5
# define ANGLE 0.1

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

void	ft_mvleft(t_env *env)
{
	if (env->map[(int)(env->posY + MVSPEED * env->dirX)][(int)(env->posX - MVSPEED * env->dirY)] == 48)
	{
		env->posX -= MVSPEED * env->dirY;
		env->posY += MVSPEED * env->dirX;
	}
	ft_launch(env);
}

void	ft_mvright(t_env *env)
{
	if (env->map[(int)(env->posY - MVSPEED * env->dirX)][(int)(env->posX + MVSPEED * env->dirY)] == 48)
	{
		env->posX += MVSPEED * env->dirY;
		env->posY -= MVSPEED * env->dirX;
	}
	ft_launch(env);
}

void	ft_roleft(t_env *env)
{
	env->dirX = cos(ANGLE) * env->dirX - sin(ANGLE) * env->dirY;
	env->dirY = sin(ANGLE) * env->dirX + cos(ANGLE) * env->dirY;
	env->dirX *= 1.0 / sqrt(env->dirX * env->dirX + env->dirY * env->dirY);
	env->dirY *= 1.0 / sqrt(env->dirX * env->dirX + env->dirY * env->dirY);
	env->planeX = cos(ANGLE) * env->planeX - sin(ANGLE) * env->planeY;
	env->planeY = sin(ANGLE) * env->planeX + cos(ANGLE) * env->planeY;
	env->planeX *= 1.0 / sqrt(env->planeX * env->planeX + env->planeY * env->planeY);
	env->planeY *= 1.0 / sqrt(env->planeX * env->planeX + env->planeY * env->planeY);
	ft_launch(env);
}

void	ft_roright(t_env *env)
{
	env->dirX = cos(-ANGLE) * env->dirX - sin(-ANGLE) * env->dirY;
	env->dirY = sin(-ANGLE) * env->dirX + cos(-ANGLE) * env->dirY;
	env->dirX *= 1.0 / sqrt(env->dirX * env->dirX + env->dirY * env->dirY);
	env->dirY *= 1.0 / sqrt(env->dirX * env->dirX + env->dirY * env->dirY);
	env->planeX = cos(-ANGLE) * env->planeX - sin(-ANGLE) * env->planeY;
	env->planeY = sin(-ANGLE) * env->planeX + cos(-ANGLE) * env->planeY;
	env->planeX *= 1.0 / sqrt(env->planeX * env->planeX + env->planeY * env->planeY);
	env->planeY *= 1.0 / sqrt(env->planeX * env->planeX + env->planeY * env->planeY);
	ft_launch(env);
}