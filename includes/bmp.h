/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:45:51 by awyart            #+#    #+#             */
/*   Updated: 2017/09/06 18:50:40 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# pragma pack(push, 1)

typedef struct 		s_img
{
	short			idfield;
	unsigned int	SzofBMP;
	short			as1;
	short			as2;
	unsigned int	offset;
	unsigned int	NbofDIBBytes;
	int				width;
	int				height;
	short			NBcol;
	short			NBpix;
	int				BI_BITFIELDS;
	unsigned int	Szray;
	int				Resh;
	int				Resv;
	unsigned int 	nbpalcol;
	unsigned int	impcol;
}					t_img;

# pragma pack(pop)

typedef struct		s_desc
{	unsigned char	***img;	
	int				width;
	int				height;
}					t_desc;

#endif