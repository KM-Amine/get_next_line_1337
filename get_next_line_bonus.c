/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:38:54 by mkhellou          #+#    #+#             */
/*   Updated: 2022/11/11 14:40:52 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *tmp)
{
	char	buff[BUFFER_SIZE + 1];
	int		is_read;

	is_read = 1;
	ft_bzero(buff, BUFFER_SIZE + 1);
	while (ft_strchr(tmp, '\n') == 0 && is_read != 0)
	{
		is_read = read(fd, buff, BUFFER_SIZE);
		if (is_read == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp = ft_strjoin(tmp, buff);
		if (tmp == NULL)
			return (NULL);
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	return (tmp);
}

char	*truncate_tmp(char *tmp, char **line)
{
	int		len;
	char	*str;

	len = 0;
	while (tmp[len] != '\n' && tmp[len] != '\0' )
		len++;
	*line = ft_substr(tmp, 0, len + 1);
	if (*line == NULL)
		return (NULL);
	if (ft_strchr(tmp, '\n') == 0)
	{
		free(tmp);
		return (NULL);
	}
	str = tmp;
	tmp = ft_substr(tmp, len + 1, ft_strlen(tmp));
	if (tmp == NULL)
	{
		free(*line);
		return (NULL);
	}
	free(str);
	return (tmp);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize || !src)
	{
		ft_bzero(dst, BUFFER_SIZE +1);
		return (ft_strlen(src));
	}
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*get_next_line(int fd)
{
	static char	buff[OPEN_MAX][BUFFER_SIZE +1];
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd == 1 || fd == 2)
		return (NULL);
	tmp = (char *)calloc(1, BUFFER_SIZE + 1);
	ft_strlcpy(tmp, buff[fd], BUFFER_SIZE + 1);
	tmp = read_line(fd, tmp);
	if (tmp == NULL)
	{	
		ft_bzero(buff[fd], BUFFER_SIZE +1);
		return (NULL);
	}
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp = truncate_tmp(tmp, &line);
	ft_strlcpy(buff[fd], tmp, BUFFER_SIZE + 1);
	free(tmp);
	return (line);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
