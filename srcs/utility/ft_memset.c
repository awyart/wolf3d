/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:11:28 by awyart            #+#    #+#             */
/*   Updated: 2017/09/07 11:57:10 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*test;
	size_t			i;

	i = 0;
	if (len == 0)
		return (b);
	test = (unsigned char*)b;
	while (i < len)
	{
		test[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
