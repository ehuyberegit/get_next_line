/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwanhuyberechts <erwanhuyberechts@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:59:29 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/15 12:30:23 by erwanhuyber      ###   ########.fr       */
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

char	*ft_strcpy(char *str1, char *str2, char *joined, int len_str1)
{
	int		i;
	int		j;
	
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

char	*ft_strjoin(char *str1, char *str2)
{
	int		len_str1;
	int		len_str2;
	char	*joined;

	if (!str1)
		len_str1 = 0;
	if (!str2)
		len_str2 = 0;	
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	joined = (char *)malloc(len_str1 + len_str2 + 1);
	if (!joined)
		return (NULL);
	joined = ft_strcpy(str1, str2, joined, len_str1);
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
