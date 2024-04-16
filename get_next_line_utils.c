/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:30:13 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/04/16 18:39:39 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>

// check the string length
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

// copy one string to another
char	*ft_strdup(const char *s)
{
	char	*sdup;
	size_t	i;

	sdup = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!sdup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

// allocate memory
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	if (count && size && count > (UINT_MAX / size))
		return (NULL);
	temp = malloc(count * size);
	if (!temp)
		return (NULL);
	while (i < count * size)
	{
		temp[i] = 0;
		i++;
	}
	return (temp);
}

// create a substring
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subs = ft_calloc(len + 1, sizeof(char));
	if (!subs)
		return (NULL);
	while (i < len)
	{
		subs[i] = s[i + start];
		i++;
	}
	return (subs);
}

// combine two strings
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sum;
	int		i;
	int		j;

	i = 0;
	j = 0;
	sum = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!sum)
		return (NULL);
	while (s1[i])
		sum[j++] = s1[i++];
	i = 0;
	while (s2[i])
		sum[j++] = s2[i++];
	sum[j] = '\0';
	return (sum);
}
