/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 12:58:27 by awyart            #+#    #+#             */
/*   Updated: 2017/09/04 18:25:14 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"
#include "../../includes/bmp.h"

t_desc 	*ft_read_img(char *str)
{
	t_desc *desc;
	char trash[1024];
	t_img img;
	int fd;
	int i;
	int x;
	int j;

	fd = open(str, O_RDONLY);
	i = 0;
	x = 0;

	
	memset(&img, 0, sizeof(img));
	read(fd, &img, 54);

	//printf("idfield:%hx\n", img.idfield);
	//printf("Size of the BMP file:%u\n", img.SzofBMP);
	//printf("Application specific:%hd\n", img.as1);
	//printf("Application specific:%hd\n", img.as2);
	//printf("Offset where the pixel array:%u\n", img.offset);
	//printf("Number of bytes in the DIB header:%u\n", img.NbofDIBBytes);
	//printf("Width of the bitmap in pixels:%d\n", img.width);
	//printf("Height of the bitmap in pixels:%d\n", img.height);
	//printf("Number of color planes being used:%hd\n", img.NBcol);
	//printf("Number of bits per pixel:%hd\n", img.NBpix);
	//printf("BI_BITFIELDS:%d\n", img.BI_BITFIELDS);
	//printf("Size of the raw bitmap data (including padding):%u\n", img.Szray);
	//printf("Print resolution of the image:%d : %d\n", img.Resh, img.Resv);
	//printf("Number of colors in the palette:%u\n", img.nbpalcol);
	//printf("0 means all colors are important:%u\n", img.impcol);
	read(fd, trash, img.offset - 54);
	
	desc = (t_desc *)malloc(sizeof(t_desc));
	desc->img = (unsigned char ***)malloc(sizeof(unsigned char**) * (img.height + 1));

	while (i <= img.height)
	{
		desc->img[i] = (unsigned char**)malloc(sizeof(unsigned char*) * (img.width + 1));
		j = 0;
		while (j <= img.width)
		{
			desc->img[i][j] = (unsigned char*)malloc(5);
			j++;
		}
		i++;
	}

	i = 0;
	j = 0;
	while (x < (img.width) * (img.height))
	{
		//printf("x: %d i: %d j:%d\n", x, i ,j);
		read(fd, &desc->img[img.height - j][i][2], 1);
		//printf("rouge:%d\n", desc->img[j][i][0]);
		read(fd, &desc->img[img.height - j][i][0], 1);
		//printf("vert:%d\n", desc->img[j][i][1]);
		read(fd, &desc->img[img.height - j][i][1], 1);
		//printf("blue:%d\n", desc->img[j][i][2]);
		read(fd, &desc->img[img.height - j][i][3], 1);
		//printf("other:%d\n", desc->img[j][i][3]);
		i++;
		if (i >= img.width)
		{
			i = 0;
			j++;
		}
		x++;
	}
	desc->width = img.width;
	desc->height = img.height;
	close(fd);
	return (desc);
}

/*int main(int ac, char **av)
{
	t_desc *desc;
	int i = -1;
	int j = -1;
	int x = 0;

	desc = ft_read_img(av[1]);
	printf("ok\n");
	return (0);
}*/