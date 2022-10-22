/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 11:57:40 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/22 18:48:52 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		buff[BUFFER_SIZE];
	int			is_read;
	int			len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	len = 0;
	if (tmp == NULL)
		tmp = (char *) ft_calloc(1, 1);
	is_read = read(fd, buff, BUFFER_SIZE);
	while (is_read)
	{
		tmp = ft_strjoin(tmp, buff);
		if (ft_strchr(tmp, '\n'))
			break ;
		is_read = read(fd, buff, BUFFER_SIZE);
	}
	len = ft_strchr(tmp, '\n') - tmp;
		line = ft_substr(tmp, 0, len + 1);
		tmp = ft_substr(tmp, len + 1, SIZE_MAX);
	}
	return (line);
}

int	main()
{
	char *str;
	int fd;

	fd = open("file.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);	
	str = get_next_line(fd);
	printf("%s",str);
}
