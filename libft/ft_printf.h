/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:35:11 by jmastora          #+#    #+#             */
/*   Updated: 2023/08/01 03:11:15 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include   <unistd.h>
# include   <stdarg.h>
# include   <stdint.h>
# include   <limits.h>

int	pf_putchar(char c);
int	pf_putstr(char *str);
int	ft_printf(const char *str1, ...);
int	pf_putnbr_base(uintptr_t n, uintptr_t base, int minus);

#endif
