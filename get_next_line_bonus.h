/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:03:37 by mkhellou          #+#    #+#             */
/*   Updated: 2022/11/13 15:48:13 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

size_t		ft_strlen(char	*s);
void		ft_bzero(void *str, size_t len);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strchr(char *str, char c);
void		ft_strlcpy(char *dest, char *src, size_t len);

char		*ft_substr(char *src, size_t start, size_t lenth);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_read_line(char *tmp, int fd);
char		*ft_turncate_line(char *tmp, char **line);

char		*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  10000000
# endif

#endif