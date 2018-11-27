/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:21:39 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/27 02:29:20 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 1

int				get_next_line(const int fd, char **line);

typedef	struct	s_save
{
	int				fd;
	char			*str;
	struct s_save	*next;
}				t_save;

#endif
