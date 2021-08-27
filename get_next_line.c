/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:28:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/27 20:22:50 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int	fd)
{
	static char	*remaining;
	ssize_t		bytes;
	char		*line;
	char		*temp_line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	if (remaining)
	{
		line = ft_strdup(remaining);
		free(remaining);
	}
	else
	{
		line = ft_strdup("");
	}
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (0);
		}
		buffer[bytes] = '\0';
		temp_line = line;
		line = ft_strjoin(temp_line, buffer);
		free(temp_line);
		if (ft_strchr(line, '\n'))
		{
			temp_line = line;
			remaining = (char *)malloc(ft_strlen(temp_line) + 1 * sizeof(char));
			ft_strlcpy(remaining, ft_strchr(temp_line, '\n') + 1, ft_strlen(temp_line));
			line = ft_substr(temp_line, 0, ft_strlen(temp_line) - ft_strlen(remaining));
			free(temp_line);
			break ;
		}
	}
	if (!bytes && line[bytes] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}
