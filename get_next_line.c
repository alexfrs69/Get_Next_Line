/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 03:06:45 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/24 07:05:03 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_save	*find_list(t_save **save, int fd)
{
	t_save *tmp;

	tmp = *save;
	while (tmp != NULL)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(tmp = (t_save*)malloc(sizeof(t_save))))
		return (0);
	if (!(tmp->str = (char*)malloc(sizeof(char))))
		return (0);
	tmp->fd = fd;
	tmp->next = *save;
	*save = tmp;
	return (tmp);
}

static	int		ft_read(t_save **elem)
{
	char		*buffer;
	int			rd;

	if (!(buffer = ft_strnew(BUFF_SIZE)))
		return (0);
	while ((rd = read((*elem)->fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		if (!((*elem)->str = ft_strjoin((*elem)->str, buffer)))
			return (0);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	ft_strdel(&buffer);
	if (rd == -1)
		return (0);
	return (1);
}

static	int		ft_getnl(t_save **elem, char **line)
{
	char	*tmp;

	if ((*elem)->str && (*elem)->str[0])
	{
		if ((tmp = ft_strchr((*elem)->str, '\n')))
		{
			if (!(*line = ft_strsub((*elem)->str, 0, tmp - (*elem)->str)))
				return (-1);
			if (!(tmp = ft_strdup((*elem)->str + (tmp - (*elem)->str) + 1)))
				return (-1);
			ft_strdel(&(*elem)->str);
			(*elem)->str = tmp;
			if ((*elem)->str[0] == '\0')
				return (2);
			return (1);
		}
		else
		{
			if (!(*line = ft_strdup((*elem)->str)))
				return (-1);
			return (2);
		}
	}
	*line = NULL;
	return (0);
}

static	void	ft_linkdel(t_save **save, t_save **elem)
{
	t_save	*prev;

	if (*elem == *save)
		*save = (*save)->next;
	else
	{
		prev = *save;
		while (prev->next != *elem && prev->next)
			prev = prev->next;
		if (prev->next == *elem)
			prev->next = (*elem)->next;
	}
	//printf("*** deleted : elem->fd = %d\n", (*elem)->fd);
	ft_strdel(&(*elem)->str);
	free(*elem);
	*elem = NULL;
}

int				get_next_line(const int fd, char **line)
{
	static t_save	*save = NULL;
	t_save			*elem;
	int				rd;
	int				ret;

	if (fd < 0 || !line )
		return (-1);
	if (!(elem = find_list(&save, fd)))
		return (-1);
	if (!(rd = ft_read(&elem)))
		return (-1);
	if ((ret = ft_getnl(&elem, line)) == 2)
	{
		ft_linkdel(&save, &elem);
	}
	//if(save == NULL)
	//	printf("SAVE NULL\n");
	//t_save *tmp;
	//tmp = save;
	//while (tmp)
	//{
	//	printf(" %d ->", tmp->fd);
	//	tmp = tmp->next;
	//}
	//printf("\n");
	return (ret);
}
