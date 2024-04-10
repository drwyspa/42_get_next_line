/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjedrycz <p.jedryczkowski@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:30:00 by pjedrycz          #+#    #+#             */
/*   Updated: 2024/04/10 22:50:20 by pjedrycz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10 
#endif

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>



char    *get_next_line(int fd);


char    *ft_strchr(const char *s, int c);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
void    *ft_calloc(size_t count, size_t size);
char    *ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_strjoin(char const *s1, char const *s2);





#endif