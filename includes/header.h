/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:27:07 by awyart            #+#    #+#             */
/*   Updated: 2017/09/02 19:22:37 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "mlx.h"

# define BUFF_SIZE 1000
# define XI 2
# define YI 2
# define WINX 800
# define WINY 600
# define NBEVE 1


typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char 				*pix;
	char				**map;
	int					x_max;
	int					y_max;
	int					x;
	int					y;
}						t_env;

typedef struct			s_ev
{	
	int					key;
	void				(*f)(t_env *env);
}						t_ev;

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
void					ft_putmap(t_env *env);
void					ft_putnbr(int n);
int						ft_init_mlx(t_env *env);




void					ft_exit(t_env *env);


#endif

