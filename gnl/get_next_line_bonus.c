/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:17:26 by hesayah           #+#    #+#             */
/*   Updated: 2019/12/15 01:24:45 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_res(char *res)
{
	char	*tmp;

	tmp = res;
	res = ft_substr(res, ft_checklen(res) + 1, ft_strlen(res));
	free(tmp);
	return (res);
}

char	*ft_start(char *res, int fd)
{
	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (!res)
	{
		if (!(res = malloc(sizeof(char))))
			return (NULL);
		res[0] = '\0';
	}
	return (res);
}

char	*ft_res2(int ret, char *res, char *buff)
{
	buff[ret] = '\0';
	res = ft_strjoin(res, buff);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*res;
	size_t		ret;

	if (fd < 0 || !line || !(res = ft_start(res, fd)))
		return (-1);
	if (ft_check(res) == 0)
	{
		*line = ft_substr(res, 0, ft_checklen(res));
		res = ft_res(res);
		return (1);
	}
	while (ft_check(res) == 1 && (ret = read(fd, buff, BUFFER_SIZE)) > 0)
		if (!(res = ft_res2(ret, res, buff)))
			return (-1);
	if (ret > 0)
	{
		*line = ft_substr(res, 0, ft_checklen(res));
		res = ft_res(res);
		return (1);
	}
	*line = ft_substr(res, 0, ft_strlen(res));
	free(res);
	res = NULL;
	return (0);
}
