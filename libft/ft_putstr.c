/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:06:44 by jmastora          #+#    #+#             */
/*   Updated: 2023/08/02 22:36:05 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pf_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (write(2, "(null)", 6));
	while (str[i])
	{
		pf_putchar(str[i]);
		i++;
	}
	return (i);
}
