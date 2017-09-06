/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 11:43:55 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 17:09:38 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		mouse_click_hook(int key)
{
	ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int		mouse_move_hook(int x1, int y1, t_env *env)
{
	double x;

	if (x1 < 0 || x1 >= WINX || y1 < 0 || y1 >= WINY)
		return (0);
	x = ((double)x1 - (double)env->x) / (0.66 * (double)WINX / 50.0);
	env->x = x1;
	if (x < 0)
		ft_roleft(env);
	else if (x > 0)
		ft_roright(env);
	else
		x = 0;
	return (0);
}