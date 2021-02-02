/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:49:02 by oozsertt          #+#    #+#             */
/*   Updated: 2021/02/02 16:15:33 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 5

char	*ft_strcat_gnl(char *s1, char *s2)
{
	char	*finalstr;
	int		finalstr_len;
	int		i;
	int		j;

	finalstr_len = ft_strlen(s1) + ft_strlen(s2);
	finalstr = (char*)malloc(sizeof(char) * finalstr_len + 1);
	if (finalstr == NULL)
		return (NULL);
	finalstr[finalstr_len] = '\0';
	j = 0;
	i = 0;
	while (s1[j] != '\0')
	{
		finalstr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		finalstr[i] = s2[j];
		i++;
		j++;
	}
	return (finalstr);
}

int		ft_fill_line(char *buffer, char *stock, char **temp)
{
	char	*temp2 = NULL;

	if (*temp != NULL)
	{
		if ((temp2 = ft_strdup(*temp)) == NULL)
			return (-1);
		free(*temp);
	}
	if (stock != NULL)
	{
		if ((*temp = ft_strjoin(stock, buffer)) == NULL)
			return (-1);
	}
	else if (temp2 == NULL)
	{
		if ((*temp = ft_strdup(buffer)) == NULL)
			return (-1);
	}
	if (temp2 != NULL)
	{
		if ((*temp = ft_strcat_gnl(temp2, buffer)) == NULL)
			return (-1);
		free(temp2);
	}
	return (1);
}

int		ft_replace_char(char *str, char old, char new)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == old)
		{
			str[i] = new;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_get_line(char *buffer, char **temp, char *stock, int *eof)
{
	int		i;
	char	*temp2;

	temp2 = ft_strdup(*temp);
	free(*temp);
	i = 0;
	while (temp[i] != '\0' && temp[i] != '\n')
		i++;
	if (temp[i] == '\0')
	{
		*eof = 1;
		
	}
	
}

int		get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp_gnl = NULL;
	int			len;
	int			end_of_file;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	len = 1;
	while (ft_strchr_gnl(buffer, '\n') == NULL && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
			return (-1);
		buffer[len] = '\0';
		if (ft_fill_line(buffer, stock, &temp_gnl) == -1)
			return (-1);
	}
	*line = ft_get_line(buffer, &temp_gnl, stock, &end_of_file);
	free(temp_gnl);
	if (*line == NULL)
		return (-1);
	if (end_of_file == 1)
		return (0);
	return (1);
}

int main(int ac, char **av)
{
	char *line;
	int fd;
	(void)ac;
	int r = 1;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("error");
		return (0);
	}
	while (r != 0)
	{
		r = get_next_line(fd, &line);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
