/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 12:58:27 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 18:21:40 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "bmp.h"

static void	ft_read_color(t_img *img, int fd, t_desc *desc)
{
	int x;
	int i;
	int j;

	x = 0;
	i = 0;
	j = 0;
	while (x < (img->width) * (img->height))
	{
		read(fd, &desc->img[img->height - j - 1][img->width - i - 1][0], 1);
		read(fd, &desc->img[img->height - j - 1][img->width - i - 1][1], 1);
		read(fd, &desc->img[img->height - j - 1][img->width - i - 1][2], 1);
		read(fd, &desc->img[img->height - j - 1][img->width - i - 1][3], 1);
		i++;
		if (i >= img->width)
		{
			i = 0;
			j++;
		}
		x++;
	}
	desc->width = img->width;
	desc->height = img->height;
}

static void	ft_assign(t_img *img, t_desc *desc)
{
	int i;
	int j;

	i = 0;
	while (i <= img->height)
	{
		if (!(desc->img[i] = (unsigned char**)malloc(
			sizeof(unsigned char*) * (img->width + 1))))
			ft_errmalloc();
		j = -1;
		while (++j <= img->width)
		{
			if (!(desc->img[i][j] = (unsigned char*)malloc(5)))
				ft_errmalloc();
		}
		i++;
	}
}

void		ft_errmalloc(void)
{
	ft_putstr("un allocation de memoire a echoue\n");
	exit(0);
}

void		ft_read_img(char *str, t_desc *desc)
{
	char	trash[1024];
	t_img	img;
	int		fd;

	fd = open(str, O_RDONLY);
	ft_memset(&img, 0, sizeof(img));
	read(fd, &img, 54);
	read(fd, trash, img.offset - 54);
	if (!(desc->img = (unsigned char ***)malloc(
			sizeof(unsigned char**) * (img.height + 1))))
		ft_errmalloc();
	ft_assign(&img, desc);
	ft_read_color(&img, fd, desc);
	close(fd);
}
