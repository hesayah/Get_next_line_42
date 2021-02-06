/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 15:49:41 by hesayah           #+#    #+#             */
/*   Updated: 2019/12/13 05:11:06 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_checklen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*new;

	if (!(new = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1))))
		return (NULL);
	i = 0;
	while (str1[i])
	{
		new[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		new[i + j] = str2[j];
		j++;
	}
	new[i + j] = '\0';
	free(str1);
	return (new);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && str[start + i] != '\0')
	{
		new[i] = str[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
