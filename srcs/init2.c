/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 19:19:57 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 19:24:46 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int 		ft_checkmap(t_env *env)
{
	if (env->x_max <= 3 || env->y_max <= 3)
	{
		ft_putstr("map trop petite");
		exit(0);
	}
	if (env->map[2][2] == 48 && env->map[2][3] == 48)
		return (1);
	return (0);
}

void 		ft_err_map(void)
{
	ft_putstr("erreur dans le chargement de la map, spawn indesirable\n");
	exit(0);	
}

void		ft_load_texture(t_env *env)
{
	env->desc[2] = ft_read_img("./texture/bluestone.bmp");
	env->desc[1] = ft_read_img("./texture/eagle.bmp");
	env->desc[0] = ft_read_img("./texture/redbrick.bmp");
	env->desc[3] = ft_read_img("./texture/colorstone.bmp");
	env->desc[4] = ft_read_img("./texture/purplestone.bmp");
	env->desc[5] = ft_read_img("./texture/aeratio.bmp");
	env->desc[6] = ft_read_img("./texture/ceiling2.bmp");
	env->desc[7] = ft_read_img("./texture/ceiling.bmp");
	env->desc[8] = ft_read_img("./texture/pkirsch.bmp");

}