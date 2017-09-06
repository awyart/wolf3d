/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 12:58:27 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 19:05:54 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"
#include "../../includes/bmp.h"


static void ft_read_color(t_img *img, int fd, t_desc *desc)
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

t_desc 	*ft_read_img(char *str)
{
	t_desc *desc;
	char trash[1024];
	t_img img;
	int fd;
	int i;
	int j;

	fd = open(str, O_RDONLY);
	i = 0;
	memset(&img, 0, sizeof(img));
	read(fd, &img, 54);
	read(fd, trash, img.offset - 54);
	desc = (t_desc *)malloc(sizeof(t_desc));
	desc->img = (unsigned char ***)malloc(sizeof(unsigned char**) * (img.height + 1));
	while (i <= img.height)
	{
		desc->img[i] = (unsigned char**)malloc(sizeof(unsigned char*) * (img.width + 1));
		j = -1;
		while (++j <= img.width)
			desc->img[i][j] = (unsigned char*)malloc(5);
		i++;
	}
	ft_read_color(&img, fd, desc);
	close(fd);
	return (desc);
}
