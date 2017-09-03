/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:19:38 by awyart            #+#    #+#             */
/*   Updated: 2017/09/03 20:32:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void ft_ray(t_env *env, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if (env->map[ray->mapY][ray->mapX] > 48)
			ray->hit = 1;
	}
}

static void	ft_init_calc(int px, t_env *env, t_ray *ray)
{
	ray->hit = 0;
	ray->side = 0;
	ray->posX = env->posX;
	ray->posY = env->posY;
	env->camX = 2.0 * (double)px / (double)WINX - 1;
	ray->dirX = env->dirX + env->planeX * env->camX;
	ray->dirY = env->dirY + env->planeY * env->camX;
	ray->mapX = (int)ray->posX;
	ray->mapY = (int)ray->posY;
	ray->deltaDistX = sqrt(1.0 + (ray->dirY * ray->dirY) / (ray->dirX * ray->dirX));
	ray->deltaDistY = sqrt(1.0 + (ray->dirX * ray->dirX) / (ray->dirY * ray->dirY));
}

static void ft_init2_calc(t_ray *ray)
{
	if (ray->dirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (ray->posX - (double)ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
	}
	if (ray->dirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (ray->posY - (double)ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
	}
}
static void ft_gety(t_ray *ray)
{
	if (ray->side == 0)
		ray->wall = (ray->mapX - ray->posX + (1 - ray->stepX) / 2) / ray->dirX;
	else 
		ray->wall = (ray->mapY - ray->posY + (1 - ray->stepY) / 2) / ray->dirY;
	ray->h = 1.5 * (int)(WINY / ray->wall);
	ray->ymin = (int)(WINY / 2 - ray->h / 2);
	ray->ymax = (int)(WINY / 2 + ray->h / 2);
	if (ray->ymin < 0)
		ray->ymin = 0;
	if (ray->ymax >= WINY)
		ray->ymax = WINY - 1;
}

int ft_launch(t_env *env)
{
	int		px;
	int		py;
	t_ray	ray;

	px = 0;
	ft_create_img(env);
	while (px <= WINX)
	{
		ft_init_calc(px, env, &ray);
		ft_init2_calc(&ray);
		ft_ray(env, &ray);
		ft_gety(&ray);
		py = -1;
		while (++py < ray.ymin)
			ft_put_px_sol(env, px, py);
		while (++py < ray.ymax)
			ft_put_px(env, &ray, px, py);
		while (++py < WINY)
			ft_put_px_plafond(env, px, py);
		px++;
	}
	ft_display_img(env);
	return (1);
}
