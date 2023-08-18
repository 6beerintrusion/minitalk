/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmastora <jmastora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:43:46 by jmastora          #+#    #+#             */
/*   Updated: 2023/08/02 21:56:35 by jmastora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <stdlib.h>

// typedef struct s_list
// {
// 	void				*content;
// 	struct s_list		*next;
// }				t_list;

char	*get_next_line(int fd, int tofree);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void*dest, const void *src, size_t n);
void	*ft_memmove(void *destination, const void *source, size_t size);
size_t	ft_strlcpy(char *dest, const char*src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int character);
int		ft_tolower(int character);
char	*ft_strchr( const char *string, int searchedChar);
char	*ft_strrchr(const char *string, int searchedChar);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	*ft_memchr(const void *str, int c, size_t size);
int		ft_memcmp(const void *s01, const void *s02, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *theString);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strdup(const char *source);
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
#endif