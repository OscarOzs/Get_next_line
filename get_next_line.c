/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:49:02 by oozsertt          #+#    #+#             */
/*   Updated: 2021/01/20 17:23:32 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

int		ft_is_end_of_file(char *buffer, int fd)
{
	char *temp;
	
	if (ft_strchr(buffer, '\0') != NULL)
		return (TRUE);
	else
		return (FALSE);
}

char	*ft_fill_stock(char *buffer, char *stock)
{
	char	*stock_updated;

	if (ft_strdup(buffer) == NULL)
		return (NULL);
	if (stock != NULL)
	{
		
		if ((stock_updated = ft_strjoin(buffer, stock)) == NULL)
			return (NULL);
		ft_memset(buffer, '\0', BUFFER_SIZE);
		return (stock_updated);
	}
	else
	{
		if ((stock_updated = ft_strdup(buffer)) == NULL)
			return (NULL);
		return (stock_updated);
	}
	free(buffer);
	return (stock_updated);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock;
	char		buffer[BUFFER_SIZE + 1];
	int len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	len = read(fd, buffer, BUFFER_SIZE);
	buffer[len] = '\0';
	while ((ft_strchr(buffer, '\n')) == NULL)
	{
		if ((stock = ft_fill_stock(buffer, stock)) == NULL)
			return (-1);
		len = read(fd, buffer, BUFFER_SIZE);
		buffer[len] = '\0';
	}
	if (ft_is_end_of_file(buffer, fd) == TRUE)
	{
		*line = ft_strjoin(stock, buffer);
		free(stock);
		return (0);
	}
	else
	{
		*line = ft_strjoin(stock, buffer);
		return (1);
	}
}

int main(int ac, char **av)
{
	char **line;
	int fd;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error");
		return (0);
	}
	while (get_next_line(fd, line) > 0)
	{
		printf("%s", *line);
		free(line);
	}

	close(fd);
	return (0);
}
