/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:53:45 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 18:54:03 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_mvleft(t_env *env)
{
	if (env->map[(int)(env->posY + 0.4 * MVSPEED * env->dirX)][(int)(env->posX - 0.2 * MVSPEED * env->dirY)] == 48)
	{
		env->posX += 0.2 * MVSPEED * env->dirY;
		env->posY -= 0.2 * MVSPEED * env->dirX;
	}
	ft_launch(env);
}

void	ft_mvright(t_env *env)
{
	if (env->map[(int)(env->posY - 0.4 * MVSPEED * env->dirX)][(int)(env->posX + 0.2 * MVSPEED * env->dirY)] == 48)
	{
		env->posX -= 0.2 * MVSPEED * env->dirY;
		env->posY += 0.2 * MVSPEED * env->dirX;
	}
	ft_launch(env);
}