/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:40:47 by oozsertt          #+#    #+#             */
/*   Updated: 2021/01/15 13:39:22 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct		s_list
{
	int				fd;
	char			*after_newline;
	struct s_list		*next;
}					t_list;

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const	char *s);
char	*ft_custom_strjoin(char *s1, char *s2);
int		ft_linelen(char *str);
void	*ft_memset(void *b, int c, size_t len);

# define DEBUG printf("ICI\n");
# define PRINTZ(x) printf("%zu\n", x);


#endif