/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 03:06:45 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/22 00:49:05 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int		ft_read(const int fd, char **save)
{
	char	buffer[BUFF_SIZE + 1];
	int		rd;

	if(!save[fd])
		if (!(save[fd] = ft_strnew(BUFF_SIZE)))
			return (0);
	while ((rd = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		if (!(save[fd] = ft_strjoin(save[fd], buffer)))
			return (0);
		ft_strclr(buffer);
	}
	if (rd == -1)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*save[MAX_FILES];
	int			i;

	if (line == NULL || fd < 0)
		return (-1);
	if(!save[fd])
		if(!ft_read(fd, save))
			return (-1);
	if (*save[fd])
	{
		i = 0;
		while (save[fd][i] != '\n' && save[fd][i])
			i++;
		if (i > 0)
		{
			*line = ft_strsub(save[fd], 0, i);
			save[fd] += i + 1;
		}
		else
		{
			*line = ft_strdup("");
			save[fd] += 1;
		}
		return (1);
	}
	*line = NULL;
	return (0);
}
