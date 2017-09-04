/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:45:51 by awyart            #+#    #+#             */
/*   Updated: 2017/09/04 17:28:24 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# pragma pack(push, 1)

typedef struct 		s_img
{
	short			idfield;//ID field (42h, 4Dh)
	unsigned int	SzofBMP;//	Size of the BMP file
	short 			as1;//Application specific
	short 			as2;//Application specific
	unsigned int 	offset;//Offset where the pixel array (bitmap data) can be found
	unsigned int	NbofDIBBytes;//	Number of bytes in the DIB header (from this point)
	int				width;//Width of the bitmap in pixels
	int				height;//Height of the bitmap in pixels
	short			NBcol;//Number of color planes being used
	short 			NBpix;//	Number of bits per pixel
	int				BI_BITFIELDS;//BI_BITFIELDS, no pixel array compression used
	unsigned int	Szray;//	Size of the raw bitmap data (including padding)
	int 			Resh; //Print resolution of the image,
	int				Resv;
	unsigned int 	nbpalcol;//Number of colors in the palette
	unsigned int	impcol;//0 means all colors are important
}					t_img;

# pragma pack(pop)

typedef struct 	s_desc
{
	unsigned char 		***img;	
	int 				width;
	int 				height;
}				t_desc;

#endif
