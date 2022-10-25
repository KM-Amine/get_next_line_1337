/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:38:54 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/25 19:32:48 by mkhellou         ###   ########.fr       */
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
			return (NULL);
		tmp = ft_strjoin(tmp, buff);
		if (tmp == NULL)
			return (NULL);
		ft_bzero(buff, BUFFER_SIZE + 1);
	}
	return (tmp);
}

char	*truncate_line(char *tmp)
{
	int	len;

	len = 0;
	while (tmp[len] != '\n' && tmp[len] != '\0' )
		len++;
	return (ft_substr(tmp, 0, len + 1));
}

char	*truncate_tmp(char *tmp)
{
	int	len;

	if (ft_strchr(tmp, '\n') == 0)
		return ((char *)ft_calloc(1, 1));
	len = 0;
	while (tmp[len] != '\n' && tmp[len] != '\0')
		len++;
	tmp = ft_substr(tmp, len + 1, ft_strlen(tmp));
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (tmp == NULL)
		tmp = (char *)ft_calloc(1, 1);
	tmp = read_line(fd, tmp);
	if (tmp[0] == '\0')
	{
		free(tmp);
		tmp = NULL;
		return (NULL);
	}
	line = truncate_line(tmp);
	str = truncate_tmp(tmp);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
	}
	free(tmp);
	tmp = str;
	return (line);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
