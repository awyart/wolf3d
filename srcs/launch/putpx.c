/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 20:29:49 by awyart            #+#    #+#             */
/*   Updated: 2017/09/05 18:10:09 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_put_px(t_env *env, t_ray *ray, int x, int y)
{
	int ry;
	int rx;

	if ((x > 0 && y > 0) && (x <= WINX && y <= WINY) && ray->nbtex < 6)
	{
		ry = (int)(((double)y - (double)ray->dep) / (double)ray->h * (double)env->desc[ray->nbtex]->height);
		rx = ray->texX;
		if (rx < env->desc[ray->nbtex]->width && ry < env->desc[ray->nbtex]->height)
		{
			env->pix[(x * 4) + (y * WINX * 4)] = env->desc[ray->nbtex]->img[ry][rx][0];
			env->pix[(x * 4) + (y * WINX * 4) + 1] =  env->desc[ray->nbtex]->img[ry][rx][1];
			env->pix[(x * 4) + (y * WINX * 4) + 2] =  env->desc[ray->nbtex]->img[ry][rx][2];
		}
	}
}

void	ft_put_px_sol(t_env *env, int x, int y)
{
	if ((x > 0 && y > 0) && (x <= WINX && y <= WINY))
	{
		env->pix[(x * 4) + (y * WINX * 4)] = 100;
		env->pix[(x * 4) + (y * WINX * 4) + 1] = 100;
		env->pix[(x * 4) + (y * WINX * 4) + 2] = 100;
	}
}

void	ft_put_px_plafond(t_env *env, int x, int y)
{
	if ((x > 0 && y > 0) && (x <= WINX && y <= WINY))
	{
		env->pix[(x * 4) + (y * WINX * 4)] = 0;
		env->pix[(x * 4) + (y * WINX * 4) + 1] = 0;
		env->pix[(x * 4) + (y * WINX * 4) + 2] = 0;
	}
}

void 	ft_display_minimap(t_env *env)
{
	int i = 0;
	int j = 0;
	int k;
	int l;

	while (i <= env->y_max + 1)
	{
		while (env->map[i][j] != '\0')
		{
			if (env->map[i][j] > 48)
			{
				k = 4 * j;
				l = 4 * i;
				env->pix[(k * 4) + (l * WINX * 4)] = 0;
				env->pix[(k * 4) + (l * WINX * 4) + 1] = 255;
				env->pix[(k * 4) + (l * WINX * 4) + 2] = 255;	
			}
			j++;
		}
		j = 0;
		i++;
	}
	i = -1;
	j = -1;
	env->pix[((4 * 3)* 4) + (4 * 19 * WINX * 4)] = 255;
	env->pix[((4 * 3)* 4) + (4 * 19 * WINX * 4) + 1] = 255;
	env->pix[((4 * 4)* 4) + (4 * 19 * WINX * 4) + 2] = 255;
	while (++i < 5)
	{
		while(++j < 5)
		{
			env->pix[((4 * (int)env->posX + j)* 4) + ((4 * (int)env->posY + i) * WINX * 4)] = 100;
			env->pix[((4 * (int)env->posX + j)* 4) + ((4 * (int)env->posY + i) * WINX * 4) + 1] = 0;
			env->pix[((4 * (int)env->posX + j)* 4) + ((4 * (int)env->posY + i) * WINX * 4) + 2] = 0;	
		}
		j = -1;
	}
}
		