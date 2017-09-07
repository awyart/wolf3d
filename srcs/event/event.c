/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:02:48 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 14:53:56 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_event(t_env *env)
{
	if (env->posx < 4 && env->posx > 3 && env->posy < 20 && env->posy > 19)
	{
		env->posx = 6;
		env->posy = 19;
		ft_launch(env);
	}
	if (env->posx < 16 && env->posx > 15 && env->posy < 20 && env->posy > 19)
	{
		env->map[19][15] = 9 + 48;
		env->posx = 6;
		env->posy = 19;
		system("afplay ./texture/vic.mp3");
	}
	ft_launch(env);
}

void	ft_star(t_env *env)
{
	env->etoile = 1;
	ft_launch(env);
}

void	ft_star2(t_env *env)
{
	env->etoile = 0;
	ft_launch(env);
}

void	ft_build(t_env *env)
{
	int i;

	i = (int)(env->posy + env->diry);
	if (env->map[i][(int)(env->posx + env->dirx)] == 48)
		env->map[i][(int)(env->posx + env->dirx)] = 56;
	ft_launch(env);
}

void	ft_del(t_env *env)
{
	int i;

	i = (int)(env->posy + env->diry);
	if (env->map[i][(int)(env->posx + env->dirx)] != 49)
		env->map[i][(int)(env->posx + env->dirx)] = 48;
	ft_launch(env);
}
