/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:55:16 by oozsertt          #+#    #+#             */
/*   Updated: 2021/03/25 14:58:40 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int main(int ac, char **av)
{
	int fd;
	char *line;
	int r = 1;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("error\n");
		return (0);
	}

	while (r != 0 && r != -1)
	{
		r = get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);		
	}
	close(fd);
}