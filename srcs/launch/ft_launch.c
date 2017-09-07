/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:19:38 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 15:05:39 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_display_img(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}

static void	ft_create_img(t_env *env)
{
	int		bpp;
	int		sizeline;
	int		endian;

	env->img = mlx_new_image(env->mlx, WINX, WINY);
	env->pix = mlx_get_data_addr(env->img, &bpp, &sizeline, &endian);
}

static void	ft_calc_text(t_env *env, t_ray *ray)
{
	ray->nbtex = env->map[ray->mapy][ray->mapx] - 49;
	if (ray->side == 0)
		ray->wallx = ray->posy + ray->wall * ray->diry;
	else
		ray->wallx = ray->posx + ray->wall * ray->dirx;
	ray->wallx -= floor(ray->wallx);
	ray->texx = (int)(ray->wallx * (double)env->desc[ray->nbtex]->width);
	if (ray->side == 0 && ray->dirx > 0)
		ray->texx = env->desc[ray->nbtex]->width - ray->texx - 1;
	if (ray->side == 1 && ray->diry < 0)
		ray->texx = env->desc[ray->nbtex]->width - ray->texx - 1;
}

static void	ft_calc_floor(t_env *env, t_ray *ray)
{
	if (ray->side == 0 && ray->dirx > 0)
	{
		env->floorx = ray->mapx;
		env->floory = ray->mapy + ray->wallx;
	}
	else if (ray->side == 0 && ray->dirx < 0)
	{
		env->floorx = ray->mapx + 1.0;
		env->floory = ray->mapy + ray->wallx;
	}
	else if (ray->side == 1 && ray->diry > 0)
	{
		env->floorx = ray->mapx + ray->wallx;
		env->floory = ray->mapy;
	}
	else
	{
		env->floorx = ray->mapx + ray->wallx;
		env->floory = ray->mapy + 1.0;
	}
	env->distwall = ray->wall;
}

int			ft_launch(t_env *env)
{
	int		px;
	int		py;
	t_ray	ray;

	px = -1;
	ft_create_img(env);
	while (++px <= WINX)
	{
		ft_init_calc(px, env, &ray);
		ft_calc_text(env, &ray);
		ft_calc_floor(env, &ray);
		py = ray.ymin;
		while (++py < ray.ymax)
			ft_put_px(env, &ray, px, py);
		py--;
		while (++(py) < WINY - 1)
		{
			ft_put_px_sol(env, &ray, px, py);
			ft_put_px_plafond(env, &ray, px, py);
		}
		if (env->drawmap == 1)
			ft_display_minimap(env);
	}
	ft_display_img(env);
	return (1);
}
