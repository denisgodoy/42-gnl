/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:28:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/26 20:41:05 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int	fd)
{
	static char	*remaining;
	ssize_t		bytes;
	size_t		flag;
	char		*line;
	char		*temp_line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 256)
		return (0);
	else if (remaining)
		line = ft_strdup(remaining);
	else
		line = ft_strdup("");
	bytes = 1;
	flag = 1;
	while (flag && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			free(remaining);
			return (0);
		}
		buffer[bytes] = '\0';
		temp_line = line;
		line = ft_strjoin(temp_line, buffer);
		free(temp_line);
		if (ft_strchr(line, '\n'))
		{
			remaining = ft_strdup(ft_strchr(line, '\n') + 1);
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(remaining));
			flag = 0;
		}
		else if (!bytes && line[0] == '\0')
		{
			free(line);
			free(remaining);
			return (0);
		}
	}
	return (line);
}
