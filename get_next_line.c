/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 03:06:45 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/19 06:11:08 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_read(int fd, char **save)
{
	int		rd;
	char	buffer[BUFF_SIZE + 1];

	if (!*save)
		if (!(*save = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
	while ((rd = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[rd] = '\0';
		if (!(*save = ft_strjoin(*save, buffer)))
			return (-1);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*save;
	int				i;

	if (!fd || fd < 0 || !line)
		return (-1);
	if (!ft_read(fd, &save))
		return (-1);
	if (*save)
	{
		i = 0;
		while (save[i] != '\n' && save[i])
			i++;
		if (i > 0)
		{
			*line = ft_strsub(save, 0, i);
			save += i + 1;
		}
		else
			*line = ft_strdup("");
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
