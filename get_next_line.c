/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:28:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/28 11:46:18 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int	fd)
{
	static char	remaining[BUFFER_SIZE + 1];
	ssize_t		bytes;
	char		*line;
	char		*temp_line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	line = ft_strdup(remaining);
	if (!line)
		return (0);
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
		if (!line)
			return (0);
		free(temp_line);
		if (ft_strchr(line, '\n'))
		{
			temp_line = line;
			ft_strlcpy(remaining, (ft_strchr(line, '\n') + 1), ft_strlen(line));
			line = ft_substr(temp_line, 0, ft_strlen(temp_line) - ft_strlen(remaining));
			if (!line)
				return (0);
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
