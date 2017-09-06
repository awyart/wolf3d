/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:02:48 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 20:25:24 by awyart           ###   ########.fr       */
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
	env->etoile += 1;
	env->etoile %= 2;
	ft_launch(env);
}

void ft_lay(t_env *env)
{
	env->lay += 1;
	env->lay %= 2;
	ft_launch(env);
}

void ft_build(t_env *env)
{
	env->map[(int)env->posY][(int)env->posX +1] = 8 + 48;
	ft_launch(env);
}