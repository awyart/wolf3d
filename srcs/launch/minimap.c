/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 15:08:00 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 15:09:17 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_display_pos(t_env *env)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < 5)
	{
		while (++j < 5)
		{
			env->pix[((8 * (int)env->posx + j) * 4) + \
				((8 * (int)env->posy + i) * WINX * 4)] = 0;
			env->pix[((8 * (int)env->posx + j) * 4) + \
				((8 * (int)env->posy + i) * WINX * 4) + 1] = 255;
			env->pix[((8 * (int)env->posx + j) * 4) + \
				((8 * (int)env->posy + i) * WINX * 4) + 2] = 255;
		}
		j = -1;
	}
}

void		ft_display_minimap(t_env *env)
{
	int i;
	int j;
	int k;
	int l;

	i = -1;
	j = 0;
	while (++i <= env->y_max + 1)
	{
		while (env->map[i][j] != '\0')
		{
			if (env->map[i][j] > 48)
			{
				k = 8 * j;
				l = 8 * i;
				env->pix[(k * 8) + (l * WINX * 8)] = 255;
				env->pix[(k * 8) + (l * WINX * 8) + 1] = 255;
				env->pix[(k * 8) + (l * WINX * 8) + 2] = 255;
			}
			j++;
		}
		j = 0;
	}
	ft_display_pos(env);
}
