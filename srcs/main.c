/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:14:05 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 13:41:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
# define KEY_PRESS 2
# define KEY_PRESS_MASK 1L<<0

static void	ft_define1_ev(t_ev ev[NBEVE])
{
	ev[0].key = 53;
	ev[1].key = 13;
	ev[2].key = 12;
	ev[3].key = 1;
	ev[4].key = 14;
	ev[5].key = 0;
	ev[6].key = 2;
	ev[7].key = 17;
	ev[8].key = 123;
	ev[9].key = 124;
	ev[10].key = 126;
	ev[11].key = 125;
	ev[12].key = 83;
	ev[13].key = 86;
	ev[14].key = 11;
	ev[15].key = 45;
	ev[16].key = 46;
	ev[17].key = 43;
	ev[18].key = 87;
	ev[19].key = 84;

}

static void	ft_define2_ev(t_ev ev[NBEVE])
{
	ev[0].f = &ft_exit;
	ev[1].f = &ft_mvfw;
	ev[2].f = &ft_mvleft;
	ev[3].f = &ft_mvbw;
	ev[4].f = &ft_mvright;
	ev[5].f = &ft_roleft;
	ev[6].f = &ft_roright;
	ev[7].f = &ft_event;
	ev[8].f = &ft_roleft;
	ev[9].f = &ft_roright;
	ev[10].f = &ft_mvfw;
	ev[11].f = &ft_mvbw;
	ev[12].f = &ft_star;
	ev[13].f = &ft_lay;
	ev[14].f = &ft_build;
	ev[15].f = &ft_del;
	ev[16].f = &ft_map;
	ev[17].f = &ft_map2;
	ev[18].f = &ft_lay2;
	ev[19].f = &ft_star2;
}

static int			my_key_func(int keycode, t_env *env)
{
	int		i;
	t_ev	eev[NBEVE];

	i = -1;
	ft_define1_ev(eev);
	ft_define2_ev(eev);
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

static void ft_free_mem(t_env *env)
{
	int j;
	int i;
	int k;

	j = env->y_max + 3;
	if (env->map)
	{
		while (--j >= 0)
			ft_memdel((void *)&env->map[j]);
		ft_memdel((void *)&env->map);
	}
	k = -1;
	i = env->desc[k]->width + 1;
	while (++k < NBIMG)
	if (env->desc[k]->img)
	{
		while (--i >= 0)
		{
			j = env->desc[k]->height + 1;
			while (--j >= 0)
				ft_memdel((void *)&env->desc[k]->img[j][i]);
			ft_memdel((void *)&env->desc[k]->img[j]);
		}
		ft_memdel((void *)&env->desc[k]->img);
	}
}

int			main(int ac, char **av)
{
	t_env env;

	if (ac != 2)
		ft_putstr("Le nombre d'argument est incorrect.\n \
			Merci de charger une map valide en argument\n");
	else
	{
		ft_load_texture(&env);
		ft_getsize(&(env),av[1]);
		ft_read(&(env), av[1]);
		ft_checkmap(&env);
		if (!(ft_init_mlx(&(env))))
			return (0);
		ft_launch(&(env));
		mlx_key_hook(env.win, my_key_func, &(env));
		mlx_expose_hook(env.win, &ft_launch, &(env));
		mlx_hook(env.win, KEY_PRESS, KEY_PRESS_MASK, &my_key_func, &env);
		mlx_hook(env.win, 6, (1L << 6), mouse_move_hook, &env);
		mlx_loop(env.mlx);
		ft_free_mem(&(env));

	}
	return (0);
}