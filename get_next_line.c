/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:18:40 by dle-fur           #+#    #+#             */
/*   Updated: 2024/11/02 14:19:30 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *line)
{
	char	*buffer;
	ssize_t	nbyte;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		return (NULL);
	}
	while (!ft_strchr(line, '\n'))
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte == 0)
			break ;
		if (nbyte == -1)
		{
			free(line);
			free(buffer);
			return (NULL);
		}
		buffer[nbyte] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

static char	*save_line(char	*line)
{
	char	*next_char;
	char	*new_line;

	next_char = ft_strchr(line, '\n');
	if (next_char == NULL)
	{
		return (NULL);
	}
	else
	{
		next_char++;
	}
	new_line = ft_strdup(next_char);
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*new_line;

	line = read_line(fd, new_line);
	new_line = save_line(line);
	return (line);
}
