/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erwanhuyberechts <erwanhuyberechts@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:59:49 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/14 16:24:03 by erwanhuyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char 	*ft_strchr(char *str, int c);
int		ft_strlen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char *ft_strdup(const char *s);
char	*ft_extract_line(char **remainder);
char	*get_next_line(int fd);

#endif