/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awyart <awyart@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:40:00 by awyart            #+#    #+#             */
/*   Updated: 2017/09/02 17:42:32 by awyart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		total_len;
	char	*tmp;
	int		i;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	if ((tmp = (char *)malloc(sizeof(char) * (total_len + 1))) == NULL)
		return (0);
	tmp[total_len] = '\0';
	while (*s1)
		tmp[i++] = *s1++;
	while (*s2)
		tmp[i++] = *s2++;
	return (tmp);
}
