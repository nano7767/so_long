/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svikornv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:57:19 by svikornv          #+#    #+#             */
/*   Updated: 2023/06/13 11:57:27 by svikornv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *buf, char *stash)
{
	int		read_size;
	char	*tmp;

	read_size = 1;
	while (read_size != 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (NULL);
		if (read_size == 0)
			break ;
		buf[read_size] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (stash);
}

char	*sepstr(char *line)
{
	int		i;
	char	*stash;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (NULL);
	stash = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (stash[0] == '\0')
		return (free(stash), NULL);
	line[i + 1] = '\0';
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((sizeof(char) * BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	line = read_file(fd, buf, stash);
	free(buf);
	buf = NULL;
	if (line == NULL)
		return (NULL);
	stash = sepstr(line);
	return (line);
}
/*
int	main()
{
	char  *line = "";
	int   fd;
	fd = open("get_next_line.c" , 0) ;
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s",line) ;
		free(line);
	}
return (0) ;
}
*/
