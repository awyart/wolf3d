/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:19:38 by awyart            #+#    #+#             */
/*   Updated: 2017/09/02 22:12:31 by awyart           ###   ########.fr       */
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

/*static void		ft_put_px(t_env *env, int x, int y)
{
	if ((x > 0 && y > 0) && (x <= env->sizex && y <= env->sizey))
	{
		env->pix[(x * 4) + (y * env->sizex * 4)] = env->b;
		env->pix[(x * 4) + (y * env->sizex * 4) + 1] = env->g;
		env->pix[(x * 4) + (y * env->sizex * 4) + 2] = env->r;
	}
}*/

static void ft_calc(int px, int py, t_env *env)
{
	while (hit == 0)
	{
		if (ray.sideDistX < ray.sideDistY)
		{
			ray.sideDistX += ray.deltaDistX;
			ray.mapX += ray.stepX;
			side = 0;
		}
		else
		{
			ray.sideDistY += ray.deltaDistY;
			ray.mapY += ray.stepY;
			side = 1;
		}
		if (env->map[ray.mapY][ray.mapX] > 0)
			hit = 1;
	}
}

static void	ft_init_calc(t_env *env, t_ray *ray)
{
	ray->hit = 0;
	ray->side = 0;
	ray->posX = env->posX;
	ray->posY = env->posY;
	//ray->dirX = env->dirX + env->planeX * env->cameraX;
	//ray->dirY = env->dirY + env->planeY * env->cameraX;
	ray->mapX = (int)ray->posX;
	ray->mapY = (int)ray->posY;
	ray->deltaDistX = sqrt(1 + (ray->dirY * ray->dirY) / (ray->dirX * ray->dirX));
	ray->deltaDistY = sqrt(1 + (ray->dirX * ray->dirX) / (ray->dirY * ray->dirY));

}
 static void ft_init2_calc(t_env *env, t_ray *ray)
 {
 	if (ray->dirX < 0)
    {
      ray->stepX = -1;
      ray->sideDistX = (ray->posX - ray->mapX) * ray->deltaDistX;
    }
    else
    {
      ray->stepX = 1;
      ray->sideDistX = (ray->mapX + 1.0 - ray->posX) * ray->deltaDistX;
    }
    if (ray->dirY < 0)
    {
      ray->stepY = -1;
      ray->sideDistY = (ray->posY - ray->mapY) * ray->deltaDistY;
    }
    else
    {
      ray->stepY = 1;
      ray->sideDistY = (ray->mapY + 1.0 - ray->posY) * ray->deltaDistY;
    }
}

int ft_launch(t_env *env)
{
	int		px;
	int		py;
	t_ray	*ray;

	px = 0;
	py = 0;
	ft_create_img(env);
	while (px < WINX)
	{
		ft_init_calc(env, ray);
		ft_init2_calc(env, ray);
		ft_calc
	}
	ft_display_img(env);
	return (1);
}
