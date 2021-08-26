/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:28:21 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/26 19:25:31 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int	fd)
{
	static char	*remaining;
	ssize_t		bytes;
	size_t		flag;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 256)
		return (0);
	else if (remaining)
	{
		line = ft_strdup("");
		line = ft_strdup(remaining);
		free(remaining);
	}
	else
		line = ft_strdup("");
	bytes = 1;
	flag = 1;
	while (flag && bytes)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			remaining = ft_strdup(ft_strchr(line, '\n') + 1);
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(remaining));
			flag = 0;
		}
		if (!bytes)
		{
			free(line);
			return(0);
		}
	}
	return (line);
}
