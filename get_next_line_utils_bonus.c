/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 21:51:03 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/11 19:23:43 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (ft_strlen(src));
	}
	return (ft_strlen(src));
}

char	*ft_strjoin_free(char *s1, char const *s2)
{
	char	*ptr;
	size_t	size;
	size_t	len;
	size_t	i;

	if (!s1)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	i = 0;
	len = ft_strlen(s1);
	while (i < size - len - 1 && s2[i])
	{
		ptr[len + i] = s2[i];
		i++;
	}
	ptr[len + i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	size;

	size = ft_strlen(s1) + 1;
	ptr = (char *)malloc(size * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s1, size);
	return (ptr);
}

char	*ft_substr_free(char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	strlen;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (start > strlen)
	{
		len = 0;
		start = strlen;
	}
	else if (start + len > strlen)
		len = strlen - start;
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	free(s);
	return (ptr);
}
