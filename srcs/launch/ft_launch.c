/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:19:38 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 11:35:14 by awyart           ###   ########.fr       */
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

static void ft_calc_text(t_env *env, t_ray *ray)
{
	ray->nbtex = env->map[ray->mapY][ray->mapX] - 49;
	if (ray->side == 0)
		ray->wallX = ray->posY + ray->wall * ray->dirY;
	else
		ray->wallX = ray->posX + ray->wall * ray->dirX;
	ray->wallX -= floor(ray->wallX);
	ray->texX = (int)(ray->wallX * (double)env->desc[ray->nbtex]->width);
	if (ray->side == 0 && ray->dirX > 0)
	 	ray->texX = env->desc[ray->nbtex]->width - ray->texX - 1;
	if (ray->side == 1 && ray->dirY < 0)
		ray->texX = env->desc[ray->nbtex]->width - ray->texX - 1;
}

static void ft_calc_floor(t_env *env, t_ray *ray)
{
	if (ray->side == 0 && ray->dirX > 0)
	{
		env->floorX = ray->mapX;
		env->floorY = ray->mapY + ray->wallX; 
	}
	else if (ray->side == 0 && ray->dirX < 0)
	{
		env->floorX = ray->mapX + 1.0;
		env->floorY = ray->mapY + ray->wallX; 
	}
	else if (ray->side == 1 && ray->dirY > 0)
	{
		env->floorX = ray->mapX + ray->wallX;
		env->floorY = ray->mapY; 
	}
	else
	{
		env->floorX = ray->mapX + ray->wallX;
		env->floorY = ray->mapY + 1.0; 
	}
	env->distPlayer = 0.0;
	env->distWall = ray->wall;
}

int ft_launch(t_env *env)
{
	int		px;
	int		py;
	t_ray	ray;

	px = 0;

	ft_create_img(env);
	if (env->drawmap == 1)
		ft_display_minimap(env);
	else
	{
		while (px <= WINX)
		{
			ft_init_calc(px, env, &ray);
			ft_calc_text(env, &ray);
			ft_calc_floor(env, &ray);
			py=ray.ymin;
			while (++py < ray.ymax)
			 	ft_put_px(env, &ray, px, py);
			py--;
			while (++(py) < WINY - 1)
			{
				ft_put_px_sol(env, &ray, px, py);
				ft_put_px_plafond(env, &ray, px, py);
			}
			px++;
		}
	}
	
	ft_display_img(env);
	return (1);
}
