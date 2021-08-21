/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:33 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/20 22:47:04 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"

char	*get_next_line(int	fd)
{
	static char	*buffer;
	char	*line;
	char	*strline;

	if (fd > 0)
	{
		line = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (!line)
			return (0);
		if (!buffer)
			buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
			if (!buffer)
				return (0);

		return (strline);
	}
	return (0);
}

int main(void)
{
	char	*str;
	int		fd;
	int		fd2;
	int		i;

    fd = open("text.txt", O_RDONLY);
    fd2 = open("text2.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%d\n", fd);
	printf("%d\n", fd2);
	printf("%s\n", str);
	i = 0;
	while (str[i] != '\0')
	{
		printf("%c\n", str[i]);
		printf("%p\n", str);
		i++;
	}
	close(fd);
	close(fd2);
	free(str);
	return (0);
}
