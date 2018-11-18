/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 03:06:45 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/18 03:34:10 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>


/*
 **	- Mettre le buffer dans la static en enlevant la ligne envoyee
 **	- gerer les cas derreur de READ()
 **	- Avancer dans les lignes a chaques appel de la fonction.
 **	- gerer plusieurs FD ?
 **/

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buffer[BUFF_SIZE];
	int			rd;
	char		*nl;

	while ((rd = read(fd, buffer, BUFF_SIZE)))
	{
		nl = ft_strchr(buffer, '\n');
		if (nl)
			break ;
	}
	return (0);
}
