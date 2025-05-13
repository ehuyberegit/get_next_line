/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuybere <ehuybere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:01:58 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/13 15:31:06 by ehuybere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
int main(void)
{
	char	*joined;
	char 	*line;
	int		i;
	
	printf("\n----- Test ft_strlen -----\n\n");
	printf("-> strlen : %d\n", ft_strlen("abcd"));
	printf("\n----- Test ft_strlen finished -----\n\n");
	
	printf("\n----- Test ft_strchr -----\n\n");
	if (ft_strchr("buffe\nrfofof", '\n'))
		printf("-> Found\n");
	else
		printf("Not found\n");
	printf("\n----- Test ft_strchr finished -----\n\n");

	printf("\n----- Test ft_strjoin -----\n\n");
	write(1, "-> ", 3);
	joined = ft_strjoin("ceciiiii ", "celaaaaa");
	i = 0;
	while (joined[i])
	{
		write (1, &joined[i], 1);
		i++;	
	}
	free (joined);
	write(1, "\n", 1);
	printf("\n----- Test ft_strjoin finished -----\n\n");

	printf("\n----- Test ft_extract_line -----\n\n");
	write(1, "-> ", 3);
	line = ft_extract_line("ceciiiii est une phrase \n cela est une deuxieme");
	i = 0;
	while (line[i])
	{
		write (1, &line[i], 1);
		i++;	
	}
	free (line);
	write(1, "\n", 1);
	printf("\n----- Test ft_extract_line finished -----\n\n");

	
	
	return (0);
}
*/

int	main(void)
{
	char	*str = NULL;
	int		fd;
	char	*files[] = {
		"secret.txt",
		NULL
	};
	int		i;
	
	i = 0;
	while(files[i])
	{
		fd = open(files[i], O_RDONLY);
		printf("name of the file read : %s \n", files[i]);
		while ((str = get_next_line(fd)))
		{
			printf("Here should appear the next line : %s", str);
			free(str);
		}
		close(fd);
		i++;
	}
	return (0);
}
