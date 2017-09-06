/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:14:05 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 17:59:10 by awyart           ###   ########.fr       */
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
	ev[13].key = 84;

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
}

int			my_key_func(int keycode, t_env *env)
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
	env->desc[8] = ft_read_img("./texture/mtrazzi.bmp");

}

int			main(int ac, char **av)
{
	t_env env;
	
	if (ac != 2)
		ft_putstr("Le nombre d'argument est incorrect\n");
	else
	{
		
		ft_load_texture(&env);
		ft_getsize(&(env),av[1]);
		ft_read(&(env), av[1]);
		ft_putmap(&(env));
		if (!(ft_checkmap(&env)))
			ft_err_map();
		if (!(ft_init_mlx(&(env))))
			return (0);
		ft_launch(&(env));
		mlx_key_hook(env.win, my_key_func, &(env));
		mlx_expose_hook(env.win, &ft_launch, &(env));
		mlx_hook(env.win, KEY_PRESS, KEY_PRESS_MASK, &my_key_func, &env);
		mlx_mouse_hook(env.win, mouse_click_hook, &env);
		mlx_hook(env.win, 6, (1L << 6), mouse_move_hook, &env);
		mlx_loop(env.mlx);
	}
	return (0);
}