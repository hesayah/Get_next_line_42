/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hesayah <hesayah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 01:17:55 by hesayah           #+#    #+#             */
/*   Updated: 2019/12/15 01:18:27 by hesayah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(char *str);
size_t	ft_check(char *str);
size_t	ft_checklen(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_substr(char *str, size_t start, size_t len);
char	*ft_res(char *res);
char	*ft_start(char *res, int fd);
char	*ft_res2(int ret, char *res, char *buff);

#endif
