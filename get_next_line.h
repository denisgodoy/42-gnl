/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: degabrie <degabrie@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 22:11:00 by degabrie          #+#    #+#             */
/*   Updated: 2021/08/31 19:39:25 by degabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

void	*ft_memset(void	*b, int	c, size_t	len);
char	*ft_strchr(const char	*s, int	c);
char	*ft_strdup(const char	*s1);
char	*ft_strjoin(char	*s1, char const	*s2);
size_t	ft_strlcpy(char	*dst,	const char	*src,	size_t	dstsize);
size_t	ft_strlen(const char	*s);
char	*ft_substr(char	*s, unsigned int	start, size_t	len);
char	*get_next_line(int	fd);

#endif