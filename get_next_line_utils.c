/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehuybere <ehuybere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:59:29 by ehuybere          #+#    #+#             */
/*   Updated: 2025/05/06 16:17:11 by ehuybere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int	ft_strchr(char *str, int c)
{
	int	i;

	i = 0;

	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	return (0);
}

int main(void)
{
	printf("----- Test ft_strchr -----\n");
	if (ft_strchr("bufferfo\nfof", '\n'))
		printf("Found");
	else
		printf("Not found");
	return (0);
}