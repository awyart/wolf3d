/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 11:21:25 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 11:30:39 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_map(t_env *env)
{
	env->drawmap = 1;
	ft_launch(env);
}

void ft_map2(t_env *env)
{
	env->drawmap = 0;
	ft_launch(env);
}

void ft_lay(t_env *env)
{
	env->lay = 1;
	ft_launch(env);
}

void ft_lay2(t_env *env)
{
	env->lay = 0;
	ft_launch(env);
}