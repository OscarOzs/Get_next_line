/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:34:52 by oozsertt          #+#    #+#             */
/*   Updated: 2021/10/07 14:40:53 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	// printf("BUFFER_SIZE=%d\n", BUFFER_SIZE);
	char *line1 = NULL;
	// char *line2 = NULL;
	int fd = open("test.txt", O_RDONLY);
	// int fd2 = open("test2", O_RDONLY);
	int i = 0;
	while (i++ < 5)
	{
		get_next_line(fd, &line1);
		// get_next_line(fd2, &line2);
		printf("%s\n", line1);
	}
	close(fd);
	// close(fd2);
}