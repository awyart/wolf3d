/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:39:10 by awyart            #+#    #+#             */
/*   Updated: 2017/09/02 17:42:38 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strsub(char *s, unsigned int start, size_t len)
{
	char			*dup;
	unsigned int	i;

	i = start;
	if (!(dup = (char*)malloc(sizeof(char) * (len) + 1)))
		return (0);
	while (i < (unsigned int)len + start)
	{
		dup[i - start] = s[i];
		i++;
	}
	dup[i - start] = '\0';
	return (dup);
}
