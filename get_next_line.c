/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:01:26 by oozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 18:17:36 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	*stock = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			len;
	int			end_of_file;

	if (!line || fd < 0 || BUFFER_SIZE < 1)
		return (ERROR);
	ft_memset(buffer, '\0', BUFFER_SIZE + 1);
	len = 1;
	*line = NULL;
	while (ft_strchr(buffer, '\n') == NULL && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len < 0)
			return (ERROR);
		buffer[len] = '\0';
		if (fill_line(line, buffer, &stock) == ERROR)
			return (ERROR);
	}
	if (get_line(line, &stock, &end_of_file) == ERROR)
		return (ERROR);
	if (end_of_file == TRUE)
		return (FALSE);
	return (TRUE);
}
