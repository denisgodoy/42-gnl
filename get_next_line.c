/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/26 00:17:31 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	"libft/libft.h"

static char	*ft_read_line(char	*line, char	*leaks, int	fd);
static char	*ft_leak_backup(char	*line, char	*leaks);

char	*get_next_line(int	fd)
{
	char		*line;
	static char	*leaks;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_strdup("");
	if (leaks)
	{
		line = ft_read_line(line, leaks, fd);
		free(leaks);
		if (ft_strchr(line, '\n'))
			leaks = ft_leak_backup(line, leaks);
		line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(leaks));
		return (line);
	}
	line = ft_read_line(line, leaks, fd);
	leaks = ft_leak_backup(line, leaks);
	line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(leaks));
	return (line);
}

static char	*ft_read_line(char	*line, char	*leaks, int	fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	size_t	found_n;

	bytes_read = 1;
	found_n = 1;
	while (found_n && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (ft_strchr(line, '\n'))
			found_n = 0;
		buffer[bytes_read] = '\0';
		line = ft_strjoin(line, buffer);
	}
	if (leaks)
		line = ft_strjoin(leaks, line);
	return (line);
}

static char	*ft_leak_backup(char	*line, char	*leaks)
{
	leaks = ft_strdup(ft_strchr(line, '\n') + 1);
	if (!leaks)
		free(leaks);
	return (leaks);
}
