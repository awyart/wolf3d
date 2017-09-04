/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 20:29:49 by awyart            #+#    #+#             */
/*   Updated: 2017/09/04 18:29:30 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_put_px(t_env *env, t_ray *ray, int x, int y)
{
	if ((x > 0 && y > 0) && (x <= WINX && y <= WINY))
	{
		if (env->map[ray->mapY][ray->mapX] == 50)
		{
			env->pix[(x * 4) + (y * WINX * 4)] = 200;
			env->pix[(x * 4) + (y * WINX * 4) + 1] = 0;
			env->pix[(x * 4) + (y * WINX * 4) + 2] = 0;
		}
		else if (env->map[ray->mapY][ray->mapX] == 51)
		{
			env->pix[(x * 4) + (y * WINX * 4)] = 200;
			env->pix[(x * 4) + (y * WINX * 4) + 1] = 200;
			env->pix[(x * 4) + (y * WINX * 4) + 2] = 200;	
		}
		else if (env->map[ray->mapY][ray->mapX] == 52)
		{
			env->pix[(x * 4) + (y * WINX * 4)] = 0;
			env->pix[(x * 4) + (y * WINX * 4) + 1] = 0;
			env->pix[(x * 4) + (y * WINX * 4) + 2] = 200;	
		}
		else
		{
			env->pix[(x * 4) + (y * WINX * 4)] = 0;
			env->pix[(x * 4) + (y * WINX * 4) + 1] = 0;
			env->pix[(x * 4) + (y * WINX * 4) + 2] = 0;	
		}
	}
}

void	ft_put_px_sol(t_env *env, int x, int y)
{
	if ((x > 0 && y > 0) && (x <= WINX && y <= WINY))
	{
		env->pix[(x * 4) + (y * WINX * 4)] = env->desc->img[y * env->desc->width/WINY][x * env->desc->height / WINX][0];
		env->pix[(x * 4) + (y * WINX * 4) + 1] = env->desc->img[y *  env->desc->width/WINY][x * env->desc->height / WINX][1];
		env->pix[(x * 4) + (y * WINX * 4) + 2] = env->desc->img[y *  env->desc->width/WINY][x * env->desc->height / WINX][2];
	}
}

void	ft_put_px_plafond(t_env *env, int x, int y)
{
	if ((x > 0 && y > 0) && (x <= WINX && y <= WINY))
	{
		env->pix[(x * 4) + (y * WINX * 4)] = env->desc->img[y * env->desc->width/WINY][x * env->desc->height / WINX][0];
		env->pix[(x * 4) + (y * WINX * 4) + 1] = env->desc->img[y *  env->desc->width/WINY][x * env->desc->height / WINX][1];
		env->pix[(x * 4) + (y * WINX * 4) + 2] = env->desc->img[y *  env->desc->width/WINY][x * env->desc->height / WINX][2];
	}
}

