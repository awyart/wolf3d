/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:02:48 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 18:51:24 by awyart           ###   ########.fr       */
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