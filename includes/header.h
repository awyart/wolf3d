/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:27:07 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 16:20:41 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "bmp.h"
# define BUFF_SIZE 1000
# define POSXI 3
# define POSYI 3
# define DIRXI -1
# define DIRYI 0
# define PLANEXI 0
# define PLANEYI 0.66
# define WINX 1920
# define WINY 1080
# define NBEVE 18
# define MVSPEED 0.5
# define ANGLE 0.2
# define FACTOR 1.001
# define NBIMG 9

typedef struct		s_gnl
{
	char			*tmp;
	char			*s;
	int				fd;
	struct s_gnl	*head;
	struct s_gnl	*next;
	struct s_gnl	*last;
}					t_gnl;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*pix;
	char				**map;
	int					x_max;
	int					y_max;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				a;
	int					x;
	double				camx;
	double				floorx;
	double				floory;
	double				distwall;
	double				currentdist;
	t_desc				*desc[NBIMG];
	int					etoile;
	int					lay;
	int					drawmap;
}						t_env;

typedef struct			s_ev
{
	int					key;
	void				(*f)(t_env *env);
}						t_ev;

typedef struct			s_ray
{
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	double				wall;
	double				wallx;
	int					texnum;
	int					ymin;
	int					ymax;
	int					texx;
	int					h;
	int					nbtex;
	int					dep;
}						t_ray;

void					ft_checkmap(t_env *env);
void					ft_load_texture(t_env *env);
void					ft_putchar(char c);
void					ft_putstr(char *str);
int						ft_strlen(char *str);
int						get_next_line(int fd, char **line);
void					ft_memdel(void **ap);
void					*ft_memmove(void *dst, void *src, size_t len);
char					*ft_strchr(char *s, int c);
char					*ft_strdup(char *s1);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strnew(size_t size);
char					*ft_strsub(char *s, unsigned int start, size_t len);
void					*ft_memalloc(size_t size);
int						ft_launch(t_env *env);
void					ft_getsize(t_env *env, char *title);
void					ft_read(t_env *env, char *title);
void					ft_putnbr(int n);
int						ft_init_mlx(t_env *env);
void					ft_put_px(t_env *env, t_ray *ray, int x, int y);
void					ft_put_px_sol(t_env *env, t_ray *ray, int x, int y);
void					ft_put_px_plafond(t_env *env, t_ray *ray, int x, int y);
int						mouse_move_hook(int x, int y, t_env *env);
void					ft_read_img(char *str, t_desc *desc);
void					ft_display_minimap(t_env *env);
void					ft_exit(t_env *env);
void					*ft_memset(void *b, int c, size_t len);
void					ft_mvfw(t_env *env);
void					ft_mvbw(t_env *env);
void					ft_roleft(t_env *env);
void					ft_event(t_env *env);
void					ft_roright(t_env *env);
void					ft_star(t_env *env);
void					ft_star2(t_env *env);
void					ft_lay(t_env *env);
void					ft_lay2(t_env *env);
void					ft_init_calc(int px, t_env *env, t_ray *ray);
void					ft_del(t_env *env);
void					ft_build(t_env *env);
void					ft_map(t_env *env);
void					ft_map2(t_env *env);
void					ft_memdel(void **ap);
void					ft_free_mem(t_env *env);
void					ft_errmalloc(void);

#endif
