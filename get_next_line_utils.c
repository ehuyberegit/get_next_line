/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuybere <ehuybere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:59:29 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/13 15:53:40 by ehuybere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		len_str1;
	int		len_str2;
	char	*joined;
	int		i;
	int		j;

	if (!str1)
		len_str1 = 0;
	if (!str2)
		len_str2 = 0;	
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	joined = (char *)malloc(len_str1 + len_str2 + 1);
	if (!joined)
		return (NULL);
	i = 0;
	if (len_str1 != 0)
	{
		while (str1[i])
		{
			joined[i] = str1[i];
			i++;	
		}
	}
	j = 0;
	while (str2[j])
		joined[i++] = str2[j++];
	joined[i] = '\0';
	return (joined);
}

char	*ft_extract_line(char *remainder)
{
	int		i;
	int		len;
	char	*line;
	
	len = 0;
	if (!remainder)
		return (NULL);
	while (remainder[len] != '\n' && remainder[len])
		len++;
	if (remainder[len] == '\n')
		line = (char *)malloc(len + 2);
	else
		line = (char *)malloc(len + 1);
	i = 0;
	while (i < len)
	{
		line[i] = remainder[i];
		i++;
	}
	if (remainder[len] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	*remainder += len;
	return (line);
}
