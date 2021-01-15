/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:40:44 by oozsertt          #+#    #+#             */
/*   Updated: 2021/01/15 15:00:32 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 32

t_list	*ft_newfile(int fd)
{
	t_list	*new_file;

	new_file = (t_list*)malloc(sizeof(t_list));
	if (new_file == NULL)
		return (NULL);
	new_file->fd = fd;
	new_file->next = NULL;
	return (new_file);
}

char	*ft_fill_line(char *line, int fd, char *buffer, t_list *file)
{
	if (ft_strchr(buffer, '\n') == NULL)
	{
		line = ft_custom_strjoin(buffer, line);
		return (line);
	}
	if (ft_strchr(buffer, '\n') != NULL)
	{
		if (file->after_newline != NULL)
		{
			printf("%s\n", file->after_newline);
			line = ft_custom_strjoin(buffer, file->after_newline);
			file->after_newline = ft_strchr(buffer, '\n');
		}
		else
			line = ft_custom_strjoin(buffer, line);
		return (line);
	}
	// if (ft_strchr(buffer, '\0') != NULL)
	// {
		
	// }
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*file = NULL;
	char			buffer[BUFFER_SIZE + 1];
	t_list			*tmp;
	size_t			len;

	if (fd < 0 || BUFFER_SIZE < 1 || line == NULL || (*line = (char*)malloc(sizeof(char))) == NULL)
		return (-1);
	line[0][0] = '\0';
	tmp = file;
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	if (file == NULL && (len = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[len] = '\0';
		file = (t_list*)malloc(sizeof(t_list));
		file->fd = fd;
		file->next = NULL;
		*line = ft_fill_line(*line, fd, buffer, file);
		return (1);
	}
	while (file != NULL)
	{
		if (file->next == NULL && (len = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[len] = '\0';
			file->next = ft_newfile(fd);
			*line = ft_fill_line(*line, fd, buffer, file);
			return (1);
		}
		file = file->next;
	}
	return (-1);
}

int main(int ac, char **av)
{
	char *line;
	int fd;


	fd = open(av[1], O_RDONLY);
	while ((get_next_line(fd, &line) > 0))
	{
		printf("main : %s\n", line);
		free(line);
	}
}