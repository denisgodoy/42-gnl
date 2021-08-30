/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:28:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/30 16:22:08 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int	fd)
{
	static char	remaining[BUFFER_SIZE + 1];
	ssize_t		bytes;
	char		*line;
	char		*temp_line;
	char		*temp_remaining;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_strdup(remaining);
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
			temp_remaining = ft_strchr(line, '\n') + 1;
			ft_strlcpy(remaining, temp_remaining, ft_strlen(temp_remaining) + 1);
			line = ft_substr(temp_line, 0, ft_strlen(temp_line) - ft_strlen(remaining));
			free(temp_line);
			break ;
		}
	}
	if (!ft_strchr(line, '\n'))
		ft_memset(&remaining, 0, ft_strlen(remaining));
	if (!bytes && line[bytes] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}
