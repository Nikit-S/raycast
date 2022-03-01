/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barcher <barcher@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 18:39:08 by barcher           #+#    #+#             */
/*   Updated: 2020/11/29 19:40:18 by barcher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin_g(char *s1, char const *s2);
size_t	ft_strlcat_g(char *dst, const char *src, size_t size);
char	*ft_strchr_g(const char *s, int c);
size_t	ft_strlen_g(const char *s);
void	*ft_memmove_g(void *dest, const void *src, size_t n);

#endif
