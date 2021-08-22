/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/21 22:42:19 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	"libft/libft.h"
#include	<stdio.h>
#include	<fcntl.h>

char	*get_next_line(int	fd)
{
	static char	**lineptr;
	static int	i;
	char		buffer[BUFFER_SIZE];
	char		*line;

	if (fd > 0)
	{
		lineptr = (char **)malloc(BUFFER_SIZE * sizeof(char *));
		while (read(fd, buffer, BUFFER_SIZE))
		{
			if (ft_strchr(buffer, '\n'))
			{
				line = (char *)malloc(ft_strlen(buffer + 1) * sizeof(char));
				ft_strlcpy(line, buffer, ft_strlen(buffer));
				*lineptr = line;
				break ;
			}
			lineptr++;
		}
		return (*lineptr);
	}
	return (0);
}

int	main(void)
{
	int f = open("test.txt", O_RDONLY);
	char	*str = get_next_line(f);
	printf("%s", str);
	printf("%p\n", str);
	return (0);
}
