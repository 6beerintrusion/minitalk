/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:19:37 by jmastora          #+#    #+#             */
/*   Updated: 2023/05/24 21:50:51 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

void	pf_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
