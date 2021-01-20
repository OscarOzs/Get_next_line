/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:49:04 by oozsertt          #+#    #+#             */
/*   Updated: 2021/01/20 14:30:48 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define TRUE 1
# define FALSE 0
# define DEBUG printf("ICI\n");

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char *s1, char *s2);


#endif