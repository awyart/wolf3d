/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 15:53:43 by awyart            #+#    #+#             */
/*   Updated: 2017/09/05 17:09:12 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
# define FACTOR 1.001

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
		env->posX += MVSPEED * env->dirY;
		env->posY -= MVSPEED * env->dirX;
	}
	ft_launch(env);
}

void	ft_mvright(t_env *env)
{
	if (env->map[(int)(env->posY - MVSPEED * env->dirX)][(int)(env->posX + MVSPEED * env->dirY)] == 48)
	{
		env->posX -= MVSPEED * env->dirY;
		env->posY += MVSPEED * env->dirX;
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
//printf("%f\n", sqrt(env->dirX * env->dirX + env->dirY * env->dirY));
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
	//printf("%f\n", sqrt(env->dirX * env->dirX + env->dirY * env->dirY));
	env->dirX = cos(-ANGLE) * env->dirX - sin(-ANGLE) * env->dirY;
	env->dirY = sin(-ANGLE) * env->dirX + cos(-ANGLE) * env->dirY;
	env->dirX *= FACTOR / sqrt(env->dirX * env->dirX + env->dirY * env->dirY); 
	env->dirY *= FACTOR / sqrt(env->dirX * env->dirX + env->dirY * env->dirY);
	env->planeY = env->dirX / (sqrt(env->dirY * env->dirY + env->dirX * env->dirX));
	env->planeX = -env->dirY * env->planeY /env->dirX ;
	ft_launch(env);
}