/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwanhuyberechts <erwanhuyberechts@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:55:46 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/15 11:35:07 by erwanhuyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// gcc -Wall -Wextra -Werror -g get_next_line.c get_next_line_utils.c main.c -o get_next_line_debug

char	*ft_extract_line_2(char **remainder, int len, char *line)
{
	int		i;
	char    *new_remainder;
	
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
		new_remainder = ft_strdup(&((*remainder)[len+1]));
	else
		new_remainder = NULL;
	free(*remainder);
	*remainder = new_remainder;
	return (line);
}

char	*ft_extract_line(char **remainder)
{
	int		len;
	char	*line;
	char	*extracted_line;
	
	if (!(*remainder))
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
	extracted_line = ft_extract_line_2(remainder, len, line);
	return (extracted_line);
}

int	ft_read(int fd, char *buffer, char **remainder)
{
	char		*temp;
	int			bytes_read;
	
	temp = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*remainder, buffer);
		free(*remainder);
		*remainder = temp;
		if (ft_strchr(*remainder, '\n'))
			break;
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	int			bytes_read;
	char		*buffer;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (remainder && ft_strchr(remainder, '\n'))
	{
		new_line = ft_extract_line(&remainder); 
		return (new_line);
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = ft_read(fd, buffer, &remainder);
	if ((!remainder || remainder[0] == '\0') && bytes_read <= 0)
	{
		free (remainder);
		remainder = NULL;
		return (NULL);
	}
	new_line = ft_extract_line(&remainder);
	return (new_line);
}

