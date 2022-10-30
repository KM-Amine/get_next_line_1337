/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:38:54 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/28 18:18:42 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

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
		return (NULL);
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = read_line(fd, tmp);
	if (tmp == NULL)
		return (NULL);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	tmp = truncate_tmp(tmp, &line);
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
