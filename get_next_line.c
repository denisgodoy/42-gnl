/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/23 22:48:04 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	"libft/libft.h"
#include	<stdio.h>
#include	<fcntl.h>

static size_t	ft_newline_len(char *line);

char	*get_next_line(int	fd)
{
	char		*buffer;
	char		*line;
	static char	*leaks;
	ssize_t		i;
	size_t		j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	line = (char *)malloc(BUFFER_SIZE * sizeof(char));
	i = 1;
	if (!leaks)
	{
		while (i > 0)
		{
			i = read(fd, buffer, BUFFER_SIZE);
			line = ft_strjoin(line, buffer);
			if (ft_strchr(line, '\n'))
			{
				leaks = ft_strdup(ft_strchr(line, '\n'));
				if (leaks[0] == '\n')
					leaks = leaks + 1;
				if (!leaks)
					free(leaks);
				break ;
			}
		}
		j = ft_newline_len(line);
		line = ft_substr(line, 0, j + 1);
		return (line);
	}
	return (0);
}

static size_t	ft_newline_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n')
		i++;
	return (i);
}

int	main(void)
{
	int i = 0;

	int f = open("test.txt", O_RDONLY);
	while (i < f)
	{
		printf("%s", get_next_line(f));
		i++;
	}
	return (0);
}
