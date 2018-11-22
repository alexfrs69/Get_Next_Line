/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 03:06:45 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/22 05:38:47 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *ft_read(int fd)
{
	char	buffer[BUFF_SIZE + 1];
	char	*ret;
	int		rd;

	if(!(ret = ft_strnew(1)))
		return (0);
	while((rd = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		if(!(ret = ft_strjoin(ret, buffer)))
			return (0);
		ft_strclr(buffer);
	}
	if(rd == -1)
		return (0);
	return (ret);
}

static	t_save	*find_list(t_save **save, int fd)
{
	t_save *tmp;

	tmp = *save;
	while(tmp)
	{
		if(tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if(!(tmp = (t_save*)malloc(sizeof(t_save))))
		return (0);
	tmp->fd = fd;
	if(!(tmp->str = ft_read(fd)))
		return (0);
	tmp->next = NULL;
	return(tmp);
}

int				get_next_line(int fd, char **line)
{
	static t_save	*save;
	t_save			*elem;

	if( fd < 0 || !line)
		return (-1);
	if(!(elem = find_list(&save, fd)))
		return (-1);
	elem->next = save;
	save = elem;
	ft_strdel(&elem->str);
	free(elem);
	elem = NULL;

	return (0);
}
