/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/31 19:36:29 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

static char	*ft_read_line(char	*line, char	*leaks, int	fd);
static char	*ft_check_eof(ssize_t bytes, char	*line, char	*leaks);

char	*get_next_line(int	fd)
{
	char		*line;
	static char	leaks[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_strdup(leaks);
	line = ft_read_line(line, &*leaks, fd);
	return (line);
}

static char	*ft_read_line(char	*line, char	*leaks, int	fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	char	*temp_leak;

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
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
		{
			temp_leak = ft_strchr(line, '\n') + 1;
			ft_strlcpy(&*leaks, temp_leak, ft_strlen(temp_leak) + 1);
			line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(&*leaks));
			break ;
		}
	}
	return (ft_check_eof(bytes_read, line, &*leaks));
}

static char	*ft_check_eof(ssize_t bytes, char	*line, char	*leaks)
{
	if (!ft_strchr(line, '\n'))
		ft_memset(&*leaks, 0, ft_strlen(&*leaks));
	if (!bytes && line[bytes] == '\0')
	{
		free(line);
		return (0);
	}
	return (line);
}

void	*ft_memset(void	*b, int	c, size_t	len)
{
	char	*str;

	str = (char *)b;
	while (len--)
		*(str++) = (unsigned char)c;
	return (b);
}

size_t	ft_strlen(const char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
