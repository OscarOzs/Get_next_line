/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:01:26 by oozsertt          #+#    #+#             */
/*   Updated: 2021/03/17 10:36:49 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat_gnl(char *s1, char *s2)
{
	char	*finalstr;
	int		finalstr_len;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	finalstr_len = ft_strlen(s1) + ft_strlen(s2);
	finalstr = (char*)malloc(sizeof(char) * finalstr_len + 1);
	if (finalstr == NULL)
		return (NULL);
	finalstr[finalstr_len] = '\0';
	j = 0;
	i = 0;
	while (s1[j] != '\0')
		finalstr[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		finalstr[i++] = s2[j++];
	return (finalstr);
}

int		ft_fill_line(char *buffer, char *stock, char **temp)
{
	char	*temp2;

	if (*temp != NULL)
	{
		if ((temp2 = ft_strdup(*temp)) == NULL)
			return (-1);
		free(*temp);
		if ((*temp = ft_strcat_gnl(temp2, buffer)) == NULL)
			return (-1);
		free(temp2);
	}
	else if (stock != NULL)
	{
		if ((*temp = ft_strjoin(stock, buffer)) == NULL)
			return (-1);
		free(stock);
	}
	else
	{
		if ((*temp = ft_strdup(buffer)) == NULL)
			return (-1);
	}
	return (1);
}

void	ft_update_line_and_stock(char *line, char *stock, char *temp)
{
	int		i;
	int		j;

	i = 0;
	while (temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = temp[i];
	i++;
	line[i] = '\0';
	j = 0;
	while (temp[i] != '\0')
	{
		stock[j] = temp[i];
		i++;
		j++;
	}
	stock[j] = '\0';
}

int		ft_get_line(char **line, char **stock, int *eof)
{
	char	*temp;
	int		i;
	int		j;

	if (ft_strchr_gnl(*line, '\n') != NULL)
	{
		*eof = 0;
		temp = ft_strdup(*line);
		free(*line);
		i = 0;
		while (temp[i] != '\n')
			i++;
		if ((*line = (char*)malloc(sizeof(char) * i + 2)) == NULL)
			return (-1);
		j = 0;
		while (temp[++i] != '\0')
			j++;
		if ((*stock = (char*)malloc(sizeof(char) * j + 1)) == NULL)
			return (-1);
		ft_update_line_and_stock(*line, *stock, temp);
		free(temp);
	}
	else if (ft_strchr_gnl(*line, '\0') != NULL)
		*eof = 1;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			len;
	int			end_of_file;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	len = 1;
	*line = NULL;
	while (ft_strchr_gnl(buffer, '\n') == NULL && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
			return (-1);
		buffer[len] = '\0';
		if (ft_fill_line(buffer, stock, line) == -1)
			return (-1);
		ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	}
	if (ft_get_line(line, &stock, &end_of_file) == -1)
		return (-1);
	if (end_of_file == 1)
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	int fd;
	char *line;
	int r;

	(void)ac;
	r = 1;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error\n");
		return (0);
	}

	while (r != 0 && r != -1)
	{
		r = get_next_line(fd, &line);
		printf("%s", line);
		free(line);
	}
	
	if (close(fd) == -1)
	{
		printf("close failed\n");
		return (0);
	}
}