/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:05:48 by oozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 18:16:46 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*stock_case(char **line, char **stock, char *buffer)
{
	*line = ft_strjoin(*stock, buffer);
	if (*line == NULL)
		return (NULL);
	free(*stock);
	*stock = NULL;
	return (*line);
}

static char	*line_exist_case(char **line, char *buffer)
{
	char	*temp;

	temp = ft_strdup(*line);
	if (temp == NULL)
		return (NULL);
	free(*line);
	*line = ft_strjoin(temp, buffer);
	if (*line == NULL)
		return (NULL);
	free(temp);
	return (*line);
}

int	fill_line(char **line, char *buffer, char **stock)
{
	if (*stock != NULL)
	{
		*line = stock_case(line, stock, buffer);
		if ((*line) == NULL)
			return (ERROR);
	}
	else if (*line != NULL)
	{
		*line = line_exist_case(line, buffer);
		if ((*line) == NULL)
			return (ERROR);
	}
	else
	{
		*line = ft_strdup(buffer);
		if (*line == NULL)
			return (ERROR);
	}
	return (TRUE);
}
