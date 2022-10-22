/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhellou < mkhellou@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:30:59 by mkhellou          #+#    #+#             */
/*   Updated: 2022/10/22 18:36:57 by mkhellou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *b, size_t len)
{
	unsigned char	*var;
	size_t			i;

	i = 0;
	var = (unsigned char *)b;
	while (i < len)
	{
		var[i] = 0;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	if (count >= 18446744073709551615UL || size >= 18446744073709551615UL)
		return (NULL);
	str = malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1);
	len += ft_strlen((s2));
	result = (char *)malloc(sizeof(char) * len + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	free(s1);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (dst == NULL && dstsize == 0)
		return (0);
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	i = 0;
	j = dst_len;
	while (src[i] && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = 0;
	return (src_len + dst_len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dstsize)
		return (ft_strlen(src));
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, &s[start], len + 1);
	return (res);
}
