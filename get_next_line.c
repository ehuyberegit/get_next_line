/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuybere <ehuybere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:55:46 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/07 15:40:54 by ehuybere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*get_next_line(int fd)
{
	int			nbyte;
	static char	*remainder;
	char		*buffer;
	char		*new_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = NULL;
	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (0);
	nbyte = read(fd, buffer, BUFFER_SIZE);
	new_line = ft_strjoin(remainder, buffer);
	if (ft_strchr(buffer, '\n'))
	{
		ft_extract_line(new_line);
	}
	
	
	
	

}

