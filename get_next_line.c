/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:29:47 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/04/26 18:37:04 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

// read the buffer and save some rest after \n is found
static char	*create_line(char *line_buffer)
{
	char	*rest;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[i + 1] == 0)
		return (NULL);
	rest = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - 1);
	if (*rest == 0)
	{
		free(rest);
		rest = NULL;
	}
	line_buffer[i + 1] = '\0';
	return (rest);
}

// check for char in the string
static char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	if (!s)
		return (NULL);
	i = 0;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *) &s[i]);
	return (NULL);
}

// read the buffer and fill the line until \n or \0
static char	*fill_line_buffer(int fd, char *rest, char *buffer)
{
	ssize_t	b_read;
	char	*temp;

	b_read = 1;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
		{
			free(rest);
			return (NULL);
		}
		else if (b_read == 0)
			break ;
		buffer[b_read] = '\0';
		if (!rest)
			rest = ft_strdup("");
		temp = rest;
		rest = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	char		*buffer;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 && BUFFER_SIZE <= 0 && read(fd, 0, 0) < 0)
	{
		free(rest);
		free(buffer);
		rest = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, rest, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	rest = create_line(line);
	return (line);
}

// int	main()
// {
// 	int	fd;
//     int i;

// 	i = 0;
//     fd = open("test.txt", O_RDONLY);
// 	while (i < 8)
//     {
//         printf("%s", get_next_line(fd));
//         i++;
//     }
// 	close(fd);
// 	return (0);
// }