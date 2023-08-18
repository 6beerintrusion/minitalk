/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 18:34:44 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 20:36:56 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char*src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((src[i] != '\0') && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
	dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
