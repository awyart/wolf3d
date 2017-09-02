/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 17:27:50 by gduron            #+#    #+#             */
/*   Updated: 2017/09/02 17:40:21 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memalloc(size_t size)
{
	char *mem;

	if (!(mem = (char*)malloc(sizeof(char) * size)))
		return (0);
	while (size--)
		mem[size] = 0;
	return ((void*)mem);
}
