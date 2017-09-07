/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:02:48 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 11:41:53 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_event(t_env *env)
{
	if (env->posX < 4.0 && env->posX > 3.0 && env->posY < 20.0 && env->posY > 19.0)
	{
		env->posX = 6;
		env->posY = 19;
		
		ft_launch(env);
	}

	if (env->posX < 16.0 && env->posX > 15.0 && env->posY < 20.0 && env->posY > 19.0)
	{
		env->map[19][15] = 9 + 48;
		env->posX = 6;
		env->posY = 19;
		system("afplay ./texture/vic.mp3");
	}
	ft_launch(env);
}

void ft_star(t_env *env)
{
	env->etoile = 1;
	ft_launch(env);
}

void ft_star2(t_env *env)
{
	env->etoile = 0;
	ft_launch(env);
}
void ft_build(t_env *env)
{
	if (env->map[(int)(env->posY + env->dirY)][(int)(env->posX +env->dirX)] == 48)	
		env->map[(int)(env->posY + env->dirY)][(int)(env->posX +env->dirX + 0.5)] = 8 + 48;
	ft_launch(env);
}

void ft_del(t_env *env)
{
	if (env->map[(int)(env->posY + env->dirY)][(int)(env->posX +env->dirX)] != 49)
		env->map[(int)(env->posY + env->dirY)][(int)(env->posX +env->dirX)] = 48;
	ft_launch(env);
}