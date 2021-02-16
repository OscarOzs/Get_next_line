/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oozsertt <oozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:48:59 by oozsertt          #+#    #+#             */
/*   Updated: 2021/02/16 16:38:16 by oozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*tempfill;

	i = 0;
	tempfill = b;
	while (i < len)
	{
		*tempfill = c;
		i++;
		tempfill++;
	}
	return (b);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			res = (char*)&s[i];
			return (res);
		}
		i++;
	}
	if (s[i] == (unsigned char)c)
	{
		res = (char*)&s[i];
		return (res);
	}
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	while (s1[len] != '\0')
		len++;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*finalstr;
	size_t	finalstr_len;
	int		j;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		finalstr_len = ft_strlen(s2);
	else if (s2 == NULL)
		finalstr_len = ft_strlen(s1);
	else
		finalstr_len = ft_strlen(s1) + ft_strlen(s2);
	if ((finalstr = (char*)malloc(sizeof(char) * finalstr_len + 1)) == NULL)
		return (NULL);
	finalstr[finalstr_len] = '\0';
	i = 0;
	j = 0;
	while (s1 && s1[j] != '\0')
		finalstr[i++] = s1[j++];
	j = 0;
	while (s2 && s2[j] != '\0')
		finalstr[i++] = s2[j++];
	return (finalstr);
}
