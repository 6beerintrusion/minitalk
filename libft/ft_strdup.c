/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:41:16 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 20:16:41 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	int		size;
	int		i;
	char	*dup;

	size = ft_strlen(source);
	i = 0;
	dup = malloc(sizeof (char) * size + 1);
	if (!(dup))
	{
		return (NULL);
	}
	while (source[i] != '\0')
	{
		dup[i] = source[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
