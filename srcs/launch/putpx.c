/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 20:29:49 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 15:23:50 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_put_px(t_env *env, t_ray *ray, int x, int y)
{
	int ry;
	int rx;

	if ((x > 0 && y > 0) && (x <= WINX && y <= WINY) && ray->nbtex < 9)
	{
		ry = (int)(((double)y - (double)ray->dep) /
			(double)ray->h * (double)env->desc[ray->nbtex]->height);
		rx = ray->texx;
		if (rx < env->desc[ray->nbtex]->width && ry <
			env->desc[ray->nbtex]->height)
		{
			env->pix[(x * 4) + (y * WINX * 4)] =
					env->desc[ray->nbtex]->img[ry][rx][0];
			env->pix[(x * 4) + (y * WINX * 4) + 1] =
					env->desc[ray->nbtex]->img[ry][rx][1];
			env->pix[(x * 4) + (y * WINX * 4) + 2] =
					env->desc[ray->nbtex]->img[ry][rx][2];
		}
	}
}

void		ft_put_px_sol(t_env *env, t_ray *ray, int x, int y)
{
	double	tmp;
	int		ry;
	int		rx;

	env->currentdist = (double)WINY / (2.0 * (double)y - (double)WINY);
	tmp = (env->currentdist) / (ray->wall);
	rx = abs((int)((tmp * env->floorx + (1.0 - tmp) * env->posx)
		* env->desc[7]->width) % env->desc[7]->width);
	ry = abs((int)((tmp * env->floory + (1.0 - tmp) * env->posy)
		* env->desc[7]->height) % env->desc[7]->height);
	if ((x > 0 && y > 0) && (x <= WINX && y <= WINY))
	{
		env->pix[(x * 4) + (y * WINX * 4)] = env->desc[7]->img[ry][rx][0];
		env->pix[(x * 4) + (y * WINX * 4) + 1] = env->desc[7]->img[ry][rx][1];
		env->pix[(x * 4) + (y * WINX * 4) + 2] = env->desc[7]->img[ry][rx][2];
	}
}

static void	ft_ciel(t_env *env, int x, int y)
{
	int tx;

	tx = ((env->dirx * 100 - (1 - env->dirx) * (y) / 8 > 0) ?
		env->dirx * 100 - (1 - env->dirx) * (y) / 8 : 0);
	env->pix[(x * 4) + ((WINY - y) * WINX * 4) + 2] =
			((100 - (y) / 8 > 0) ? 100 - (y) / 8 : 0);
	env->pix[(x * 4) + ((WINY - y) * WINX * 4) + 1] =
			((100 - (y) / 8 > 0) ? 100 - (y) / 8 : 0);
	env->pix[(x * 4) + ((WINY - y) * WINX * 4)] = tx;
	if (env->etoile == 1 && rand() % 3000 == 1)
	{
		env->pix[(x * 4) + ((WINY - y) * WINX * 4)] = 255;
		env->pix[(x * 4) + ((WINY - y) * WINX * 4) + 1] = 255;
		env->pix[(x * 4) + ((WINY - y) * WINX * 4) + 2] = 255;
	}
}

void		ft_put_px_plafond(t_env *env, t_ray *ray, int x, int y)
{
	double	tmp;
	int		ry;
	int		rx;

	if ((x > 0 && y > 0) && (x < WINX && y < WINY))
	{
		if (env->lay == 1)
			ft_ciel(env, x, y);
		else
		{
			env->currentdist = (double)WINY / (2.0 * y - (double)WINY);
			tmp = (env->currentdist) / (ray->wall);
			rx = abs((int)(((tmp * env->floorx + (1.0 - tmp) * env->posx)
				* env->desc[6]->width)) % env->desc[6]->width);
			ry = abs((int)(((tmp * env->floory + (1.0 - tmp) * env->posy)
				* env->desc[6]->height)) % env->desc[6]->height);
			env->pix[(x * 4) + ((WINY - y) * WINX * 4)] =
					env->desc[6]->img[ry][rx][0];
			env->pix[(x * 4) + ((WINY - y) * WINX * 4) + 1] =
					env->desc[6]->img[ry][rx][1];
			env->pix[(x * 4) + ((WINY - y) * WINX * 4) + 2] =
					env->desc[6]->img[ry][rx][2];
		}
	}
}
