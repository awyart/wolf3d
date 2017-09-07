/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 18:56:00 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 14:58:54 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_gety(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall = (ray->mapx - ray->posx + (1 - ray->stepx) / 2) / ray->dirx;
	else
		ray->wall = (ray->mapy - ray->posy + (1 - ray->stepy) / 2) / ray->diry;
	ray->h = 1.0 * (int)(WINY / ray->wall);
	ray->ymin = (int)(WINY / 2 - ray->h / 2);
	ray->ymax = (int)(WINY / 2 + ray->h / 2);
	ray->dep = ray->ymin;
	if (ray->ymin < 0)
		ray->ymin = 0;
	if (ray->ymax >= WINY)
		ray->ymax = WINY - 1;
}

static void	ft_init2_calc(t_ray *ray)
{
	if (ray->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (ray->posx - (double)ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - ray->posx) * ray->deltadistx;
	}
	if (ray->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (ray->posy - (double)ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - ray->posy) * ray->deltadisty;
	}
}

static void	ft_ray(t_env *env, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (env->map[ray->mapy][ray->mapx] > 48)
			ray->hit = 1;
	}
}

void		ft_init_calc(int px, t_env *env, t_ray *ray)
{
	ray->hit = 0;
	ray->side = 0;
	ray->posx = env->posx;
	ray->posy = env->posy;
	env->camx = 2.0 * (double)px / (double)WINX - 1;
	ray->dirx = env->dirx + env->planex * env->camx;
	ray->diry = env->diry + env->planey * env->camx;
	ray->mapx = (int)floor(ray->posx);
	ray->mapy = (int)floor(ray->posy);
	ray->deltadistx = sqrt(1.0 + \
		(ray->diry * ray->diry) / (ray->dirx * ray->dirx));
	ray->deltadisty = sqrt(1.0 + \
		(ray->dirx * ray->dirx) / (ray->diry * ray->diry));
	ft_init2_calc(ray);
	ft_ray(env, ray);
	ft_gety(ray);
}
