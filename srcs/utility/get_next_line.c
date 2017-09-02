/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:35:35 by awyart            #+#    #+#             */
/*   Updated: 2017/09/02 17:20:53 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

typedef struct		s_gnl
{
	char			*tmp;
	char			*s;
	int				fd;
	struct s_gnl	*head;
	struct s_gnl	*next;
	struct s_gnl	*last;
}					t_gnl;

struct s_gnl		*add_or_find_gnl(struct s_gnl *head, int fd)
{
	struct s_gnl	*last;
	struct s_gnl	*curr;

	curr = head;
	last = head;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		last = curr;
		curr = curr->next;
	}
	if (!(curr = (t_gnl*)malloc(sizeof(t_gnl))))
		return (0);
	if (!(curr->s = ft_strdup("")))
		return (0);
	curr->tmp = 0;
	curr->next = 0;
	curr->fd = fd;
	curr->head = (head ? head : curr);
	curr->last = last;
	last ? (last->next = curr) : 0;
	return (curr);
}

struct s_gnl		*init_or_finish_gnl(struct s_gnl **gnl, int fd, int init, int ret)
{
	struct s_gnl	*tmp;

	if (init)
		return (add_or_find_gnl(*gnl ? (*gnl)->head : 0, fd));
	if ((tmp = (*gnl)->next) && (*gnl)->head == *gnl)
	{
		while (tmp)
		{
			tmp->head = (*gnl)->next;
			tmp = tmp->next;
		}
	}
	tmp = ((*gnl)->head != *gnl ? (*gnl)->head : (*gnl)->next);
	(*gnl)->last ? ((*gnl)->last->next = (*gnl)->next) : 0;
	(*gnl)->next ? ((*gnl)->next->last = (*gnl)->last) : 0;
	ret == -1 ? free((*gnl)->s) : 0;
	(*gnl)->s = 0;
	free(*gnl);
	(*gnl) = 0;
	return (tmp);
}

int				waiting_line(struct s_gnl **g, char **line, char *nl, int ret)
{
	free(nl);
	if (!(*g)->s)
		return (-1);
	nl = ft_strchr((*g)->s, '\n');
	nl ? *line = ft_strsub((*g)->s, 0, nl - (*g)->s) : \
		(*line = ft_strdup((*g)->s));
	if (!(*line))
		return (-1);
	nl ? ((*g)->s = ft_memmove((*g)->s, nl + 1, ft_strlen(nl))) : 0;
	if ((*g)->s[0] == 0 && !nl)
	{
		*g = init_or_finish_gnl(g, (*g)->fd, 0, -1);
		return (0);
	}
	ret = ((*((*g)->s) == 0 && nl) ? 1 : 0);
	ret ? *g = init_or_finish_gnl(g, (*g)->fd, 0, -1) : 0;
	!nl ? *g = init_or_finish_gnl(g, (*g)->fd, 0, -1) : 0;
	return (1);
}

int						get_next_line(const int fd, char **line)
{
	static struct s_gnl	*g;
	char				*buff;
	long				ret;

	if (fd < 0 || !line || BUFF_SIZE < 1 || \
			!(buff = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (!(g = init_or_finish_gnl(&g, fd, 1, 0)))
		return (-1);
	while (((ret = read(fd, buff, BUFF_SIZE)) > 0 || g->s) && ret != -1)
	{
		buff[ret] = '\0';
		!(g->tmp = ft_strjoin(g->s, buff)) ? free(buff) : 0;
		if (g->tmp == 0)
			return (-1);
		ft_memdel((void**)&(g->s));
		g->s = ft_strdup(g->tmp);
		free(g->tmp);
		if (ft_strchr(g->s, '\n') || !ret)
			return (waiting_line(&g, line, buff, ret));
	}
	g = init_or_finish_gnl(&g, fd, 0, 0);
	free(buff);
	return (ret == 0 ? 0 : -1);
}
