/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/24 16:00:48 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	"libft/libft.h"
#include	<stdio.h>
#include	<fcntl.h>

static char	*ft_check_leak(char	*leaks, char	*line, int	fd);
static char	*ft_leak_backup(char	*line, char	*leaks);

char	*get_next_line(int	fd)
{
	char		*buffer;
	char		*line;
	static char	*leaks;
	ssize_t		i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	line = ft_strdup("");
	if (leaks)
	{
		line = ft_check_leak(leaks, line, fd);
		free(leaks);
		if (ft_strchr(line, '\n'))
			leaks = ft_leak_backup(line, leaks);
		line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(leaks));
		return (line);
	}
	i = 1;
	while (i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	leaks = ft_leak_backup(line, leaks);
	line = ft_substr(line, 0, ft_strlen(line) - ft_strlen(leaks));
	free(buffer);
	return (line);
}

static char	*ft_check_leak(char	*leaks, char	*line, int	fd)
{
	char	*buffer;
	char	*new_buffer;
	ssize_t	i;
	size_t	len;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	i = 1;
	while (i > 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
	}
	len = ft_strlen(line) + ft_strlen(leaks);
	new_buffer = (char *)malloc(len * sizeof(char));
	new_buffer = ft_strjoin(leaks, line);
	return (new_buffer);
}

static char	*ft_leak_backup(char	*line, char	*leaks)
{
	leaks = ft_strdup(ft_strchr(line, '\n') + 1);
	if (!leaks)
		free(leaks);
	return (leaks);
}

int	main(void)
{
	int i = 0;
	char *line;

	int f = open("test.txt", O_RDONLY);
	while (i < f)
	{
		line = get_next_line(f);
		printf("Line %d:\t %s", i, line);
		free(line);
		i++;
	}
	return (0);
}
