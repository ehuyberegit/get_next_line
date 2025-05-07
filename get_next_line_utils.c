/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuybere <ehuybere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:59:29 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/07 15:30:24 by ehuybere         ###   ########.fr       */
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

	if (!str1 || !str2)
		return (NULL);
	len_str1 = ft_strlen(str1);
	len_str2 = ft_strlen(str2);
	joined = (char *)malloc(len_str1 + len_str2 + 1);
	if (!joined)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		joined[i] = str1[i];
		i++;	
	}
	j = 0;
	while (str2[j])
		joined[i++] = str2[j++];
	joined[i] = '\0';
	return (joined);
}

char	*ft_extract_line(char *str)
{
	int		i;
	int		len;
	char	*line;
	
	len = 0;
	if (!str)
		return (NULL);
	while (str[len] != '\n' && str[len])
		len++;
	line = (char *)malloc(len + 2);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\n';
	line[i] = '\0';
	return (line);
}

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