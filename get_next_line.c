/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuybere <ehuybere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:55:46 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/06 16:09:07 by ehuybere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Here's a high-level approach to understand what you'll be doing:

Read a chunk of data from the file descriptor
Look for a newline character in what you've read
If found, return everything up to and including that newline
If not found, continue reading until you find a newline or reach EOF
Store any extra data for the next function call
*/

#include "get_next_line.h"

void ft_read(int fd)
{
	char	*buffer;
	int		nbyte;

	
	buffer = (char *)malloc(BUFFER_SIZE);
	nbyte = read(fd, buffer, BUFFER_SIZE);
	if (ft_strchr(buffer, '\n'))
	{
		
	}
	return (bytes_read);
}

void ft_nl()
{
	
}

void ft_memo(int fd)
{
	char	*buffer;
		
	bytes_read = read(fd, buffer, nbyte);
	buffer = (char *)malloc(bytes_read + 1);
}

char	*get_next_line(int fd)
{
	int			nbyte;
	static char	*rest;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest = NULL;
	nbyte = ft_read(fd);
	
	

}

