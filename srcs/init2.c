/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:19:57 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 16:24:42 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_checkmap(t_env *env)
{
	if (env->x_max <= 3 || env->y_max <= 3)
	{
		ft_putstr("map trop petite");
		exit(0);
	}
	if (env->map[2][2] != 48 || env->map[2][3] != 48)
	{
		ft_putstr("erreur dans le chargement de la map, spawn indesirable\n");
		exit(0);
	}
}

void		ft_load_texture(t_env *env)
{
	int i;

	i = -1;
	while (++i < NBIMG)
		if (!(env->desc[i] =(t_desc*)malloc(sizeof(t_desc))))
			ft_errmalloc();
	ft_read_img("./texture/bluestone.bmp", env->desc[2]);
	ft_read_img("./texture/eagle.bmp", env->desc[1]);
	ft_read_img("./texture/redbrick.bmp", env->desc[0]);
	ft_read_img("./texture/colorstone.bmp", env->desc[3]);
	ft_read_img("./texture/purplestone.bmp", env->desc[4]);
	ft_read_img("./texture/aeratio.bmp", env->desc[5]);
	ft_read_img("./texture/ceiling2.bmp", env->desc[6]);
	ft_read_img("./texture/ceiling.bmp", env->desc[7]);
	ft_read_img("./texture/pkirsch.bmp", env->desc[8]);
}

static void	ft_free_mod(t_env *env)
{
	int j;
	int i;

	j = env->y_max + 4;
	i = NBIMG;
	if (env->map)
	{
		while (--j >= 0)
			ft_memdel((void *)&env->map[j]);
		ft_memdel((void *)&env->map);
	}
	while (--i >= 0)
		ft_memdel((void *)&env->desc[i]);
}

void		ft_free_mem(t_env *env)
{
	int j;
	int i;
	int k;

	ft_free_mod(env);
	k = -1;
	i = env->desc[k]->width + 4;
	while (++k < NBIMG)
	{
		if (env->desc[k]->img)
		{
			while (--i >= 0)
			{
				j = env->desc[k]->height + 4;
				while (--j >= 0)
					ft_memdel((void *)&env->desc[k]->img[j][i]);
				ft_memdel((void *)&env->desc[k]->img[j]);
			}
			ft_memdel((void *)&env->desc[k]->img);
		}
	}
}
