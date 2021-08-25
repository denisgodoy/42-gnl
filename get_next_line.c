/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/24 20:29:55 by degabrie         ###   ########.fr       */
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
	line = "";
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
	ssize_t	i;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
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
