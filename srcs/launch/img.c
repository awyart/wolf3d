/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 20:28:50 by awyart            #+#    #+#             */
/*   Updated: 2017/09/03 20:30:01 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_display_img(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	mlx_destroy_image(env->mlx, env->img);
}

void	ft_create_img(t_env *env)
{
	int		bpp;
	int		sizeline;
	int		endian;

	env->img = mlx_new_image(env->mlx, WINX, WINY);
	env->pix = mlx_get_data_addr(env->img, &bpp, &sizeline, &endian);
}
