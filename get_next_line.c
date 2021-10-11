/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/10/11 19:22:44 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static char	*ft_read_line(char *line, char **leaks, int fd);
static char	*ft_check_eof(ssize_t bytes, char *line);
static char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*leaks;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	if (!leaks)
		leaks = ft_strdup("");
	line = ft_strdup(leaks);
	free(leaks);
	leaks = NULL;
	line = ft_read_line(line, &leaks, fd);
	return (line);
}

static char	*ft_read_line(char *line, char **leaks, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(line);
			return (0);
		}
		buffer[bytes_read] = '\0';
		line = ft_strjoin_free(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			*leaks = ft_strdup(ft_strchr(line, '\n') + 1);
			line = ft_substr_free(line, 0, ft_strlen(line) - ft_strlen(*leaks));
			break ;
		}
	}
	return (ft_check_eof(bytes_read, line));
}

static char	*ft_check_eof(ssize_t bytes, char *line)
{
	if (!bytes && line[bytes] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}

static char	*ft_strchr(const char *s, int c)
{
	char	*nb;

	nb = (char *)&s[(ft_strlen(s))];
	if ((char)c == '\0')
		return (nb);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}
