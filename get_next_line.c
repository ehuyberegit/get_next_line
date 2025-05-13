/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuybere <ehuybere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:55:46 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/13 15:54:17 by ehuybere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// gcc -Wall -Wextra -Werror -g get_next_line.c get_next_line_utils.c main.c -o get_next_line_debug

char	*get_next_line(int fd)
{
	int			bytes_read;
	static char	*remainder;
	char		*buffer;
	char		*new_line;
	char		*joined;
	

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	//Check if remainder already has a newline if remainder contains '\n'
	if (remainder && ft_strchr(remainder, '\n'))
	{
		// extract line from remainder
		new_line = ft_extract_line(remainder); 
		printf("DEBUG: new line after extraction 1: %s\n", new_line);
		// return new line
		return (new_line);
	}
	
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	
	bytes_read = 0;
	while (!ft_strchr(buffer, '\n') && bytes_read != (-1))
	{
		// Read a line from a file descriptor (up to a newline character)
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		printf("DEBUG: bytes read: %d\n", bytes_read);
		if (bytes_read <= 0)
			break;
		// If new line not found, add the new buffer to the total read buffer
		buffer[bytes_read] = '\0';
		printf("DEBUG: buffer content: '%s'\n", buffer);
		joined = NULL;
		joined = ft_strjoin(remainder, buffer);
		free(remainder);
		printf("DEBUG: remainder after join: %s\n", joined);
		if (ft_strchr(remainder, '\n'))
			break;
	}
	new_line = ft_extract_line(remainder);
	printf("DEBUG: new line after extraction 2: %s\n", new_line);
	if (ft_strchr(buffer, '\n') || EOF)
	{
		free (remainder);
		free(buffer);
		return (NULL);
	} 
	remainder = NULL;
	return (new_line);
}
