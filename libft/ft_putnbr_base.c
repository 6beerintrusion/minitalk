/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:51:15 by jmastora          #+#    #+#             */
/*   Updated: 2023/08/02 22:12:03 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define BASE "0123456789ABCDEF0123456789abcdef"

int	pf_putnbr_base(uintptr_t n, uintptr_t base, int minus)
{
	static int	count;

	count = 0;
	if (n > base - 1)
	{
		pf_putnbr_base(n / base, base, minus);
	}
	count = count + pf_putchar(BASE[minus * 16 + n % base]);
	return (count);
}
