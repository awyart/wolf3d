/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 15:45:51 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 14:30:42 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# pragma pack(push, 1)

typedef struct		s_img
{
	short			idfield;
	unsigned int	szofbmp;
	short			as1;
	short			as2;
	unsigned int	offset;
	unsigned int	nbofdibbytes;
	int				width;
	int				height;
	short			nbcol;
	short			nbpix;
	int				bibitfiels;
	unsigned int	szray;
	int				resh;
	int				resv;
	unsigned int	nbpalcol;
	unsigned int	impcol;
}					t_img;

# pragma pack(pop)

typedef struct		s_desc
{
	unsigned char	***img;
	int				width;
	int				height;
}					t_desc;

#endif
