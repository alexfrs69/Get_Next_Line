/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 03:06:43 by afrancoi          #+#    #+#             */
/*   Updated: 2018/11/22 03:23:37 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 50

int					get_next_line(const int fd, char **line);

typedef struct 		s_save
{
	int				fd;
	char			*str;
	struct s_save	*next;
}					t_save;

#endif
