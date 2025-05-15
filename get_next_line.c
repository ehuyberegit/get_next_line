/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwanhuyberechts <erwanhuyberechts@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:55:46 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/14 17:33:41 by erwanhuyber      ###   ########.fr       */
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
	char		*temp;
	
	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
		
	if (remainder && ft_strchr(remainder, '\n'))
	{
		new_line = ft_extract_line(&remainder); 
		//printf("DEBUG: new line if the remainder had nl: %s\n", new_line);
		return (new_line);
	}
	
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		//printf("DEBUG: bytes read: %d\n", bytes_read);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		//printf("DEBUG: buffer content: '%s'\n", buffer);
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
		//printf("DEBUG: remainder after join: %s\n", joined);
		if (ft_strchr(remainder, '\n'))
			break;
	}
	free(buffer);

	
	if ((!remainder || remainder[0] == '\0') && bytes_read <= 0)
	{
		free (remainder);
		remainder = NULL;
		return (NULL);
	}
	
	new_line = ft_extract_line(&remainder);
	
	return (new_line);
}
