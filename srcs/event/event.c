/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 18:02:48 by awyart            #+#    #+#             */
/*   Updated: 2017/09/05 18:55:15 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_event(t_env *env)
{
	if (env->posX < 4.0 && env->posX > 3.0 && env->posY < 20.0 && env->posY > 19.0)
	{
		env->posX = posXI;
		env->posY = posYI;
		
		ft_launch(env);
	}
	//PlaySound("./texture/son.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	ft_launch(env);
}