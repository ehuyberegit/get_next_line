/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwanhuyberechts <erwanhuyberechts@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:59:29 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/14 17:37:23 by erwanhuyber      ###   ########.fr       */
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
char *ft_strdup(const char *s)
{
    char *dup;
    int len;
    int i;

    if (!s)
        return (NULL);
    
    len = ft_strlen((char *)s);
    dup = (char *)malloc(len + 1);
    if (!dup)
        return (NULL);
    
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    
    return (dup);
}

char	*ft_extract_line(char **remainder)
{
	int		i;
	int		len;
	char	*line;
	char    *new_remainder;
	
	if (!*remainder)
		return (NULL);

	len = 0;
	while ((*remainder)[len] != '\n' && (*remainder)[len])
		len++;
	
	if ((*remainder)[len] == '\n')
		line = (char *)malloc(len + 2);
	else
		line = (char *)malloc(len + 1);
	if (!line)
        return (NULL);

	i = 0;
	while (i < len)
	{
		line[i] = (*remainder)[i];
		i++;
	}
	if ((*remainder)[len] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	if ((*remainder)[len] == '\n')
		new_remainder = ft_strdup(&(*remainder)[len+1]);
	else
		new_remainder = NULL;
	free(*remainder);
	*remainder = new_remainder;
	return (line);
}
