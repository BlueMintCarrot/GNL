/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joanda-s <joanda-s@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 20:05:53 by joanda-s          #+#    #+#             */
/*   Updated: 2023/08/29 20:40:08 by joanda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];
	int			i;

	i = 0;
	line = NULL;
	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		ft_clearbuf(buffer);
		return (NULL);
	}
	while (buffer[i] != '\n' && i < BUFFER_SIZE)
		i++;
	while (*buffer != 0 || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_checknl(buffer))
			break ;
	}
	return (line);
}
