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
	char		*line;
	char		*strline;

	if (fd > 0)
	{
		line = (char *)malloc(BUFFER_SIZE * sizeof(char));
		if (!line)
			return (0);
		if (!buffer)
		{
			buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
			if (!buffer)
				return (0);
		}
		return (strline);
	}
	return (0);
}

