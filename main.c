/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:14:05 by awyart            #+#    #+#             */
/*   Updated: 2017/09/02 19:21:39 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_define1_ev(t_ev ev[NBEVE])
{
	ev[0].key = 53;
}

static void	ft_define2_ev(t_ev ev[NBEVE])
{
	ev[0].f = &ft_exit;
}

int			my_key_func(int keycode, t_env *env)
{
	int		i;
	t_ev	eev[NBEVE];

	i = -1;
	ft_define1_ev(eev);
	ft_define2_ev(eev);
	//ft_putnbr(keycode);
	//ft_putchar('\n');
	while (++i < NBEVE)
	{
		if (keycode == eev[i].key)
		{
			eev[i].f(env);
			break ;
		}
	}
	return (0);
}

int			main(int ac, char **av)
{
	t_env env;

	if (ac != 2)
	{
		ft_putstr("Le nombre d'argument est incorrect\n");
		return (0);
	}
	else
	{
		ft_getsize(&(env),av[1]);
		ft_read(&(env), av[1]);
		ft_putmap(&(env));
		if (!(ft_init_mlx(&(env))))
			return (0);
		ft_launch(&(env));
		mlx_key_hook(env.win, my_key_func, &(env));
		mlx_expose_hook(env.win, &ft_launch, &(env));
		//mlx_loop_hook(env.mlx, loop_hook, env);
		mlx_loop(env.mlx);
		return (0);
	}
}
