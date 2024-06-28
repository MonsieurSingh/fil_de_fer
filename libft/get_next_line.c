/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tesingh <tesingh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 15:27:11 by tesingh           #+#    #+#             */
/*   Updated: 2024/03/23 15:27:15 by tesingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*init(void)
{
	return ((char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)));
}

int	byte_read(int fd, char *c, int *bytes_read)
{
	*bytes_read = (int)(read(fd, c, sizeof(char)));
	return (*bytes_read);
}

char	*read_line(int fd, char *line)
{
	int		i;
	char	c;
	int		bytes_read;

	i = 0;
	while (byte_read(fd, &c, &bytes_read) > 0)
	{
		line[i++] = c;
		if (i >= BUFFER_SIZE)
		{
			line = ft_realloc(line, i, i * 2);
			if (!line)
				return (NULL);
		}
		if (c == '\n')
			break ;
	}
	if (bytes_read < 0 || (bytes_read == 0 && i == 0))
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = init();
	if (!line)
		return (NULL);
	line = read_line(fd, line);
	return (line);
}
