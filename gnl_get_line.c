/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_get_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:20:03 by oozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 19:10:34 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	fill_line_and_stock(char *line, char *stock, char *temp)
{
	int		i;
	int		j;

	i = 0;
	while (temp[i] != '\n')
	{
		line[i] = temp[i];
		i++;
	}
	line[i] = '\0';
	i++;
	j = 0;
	while (temp[i] != '\0')
	{
		stock[j] = temp[i];
		i++;
		j++;
	}
	stock[j] = '\0';
}

static char	*malloc_line_and_stock(char **line, char **stock, char *temp)
{
	int		i;
	int		j;

	temp = ft_strdup(*line);
	free(*line);
	i = 0;
	while (temp[i] != '\n')
		i++;
	*line = (char *)malloc(sizeof(char) * (i + 1));
	if ((*line) == NULL)
		return (NULL);
	j = 0;
	while (temp[++i] != '\0')
		j++;
	*stock = (char *)malloc(sizeof(char) * (j + 1));
	if ((*stock) == NULL)
		return (NULL);
	return (temp);
}

int	get_line(char **line, char **stock, int *eof)
{
	char	*temp;

	temp = NULL;
	if (ft_strchr(*line, '\n') != NULL)
	{
		*eof = 0;
		temp = malloc_line_and_stock(line, stock, temp);
		if (temp == NULL)
			return (ERROR);
		fill_line_and_stock(*line, *stock, temp);
		free(temp);
	}
	else if (ft_strchr(*line, '\0') != NULL)
		*eof = TRUE;
	return (TRUE);
}
