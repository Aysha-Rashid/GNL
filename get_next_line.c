/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayal-ras <ayal-ras@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 21:06:01 by ayal-ras          #+#    #+#             */
/*   Updated: 2023/09/09 21:03:12 by ayal-ras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buffer = read_lines(fd, buffer);
	if (!buffer)
		return (NULL);
	line = new_line(buffer);
	buffer = remaining(buffer);
	return (line);
}

char	*read_lines(int fd, char *store)
{
	char	*buffer;
	int		bytes;

	bytes = 1;
	buffer = malloc(BUFFER_SIZE + 2);
	if (store == NULL)
		store = ft_strdup("");
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(store);
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		store = ft_strjoin(store, buffer);
		if (ft_strchr(store, '\n') != NULL) 
			break ;
	}
	return (free(buffer), store);
}

char	*new_line(char *buffer)
{
	char		*line;
	int			i;
	int			j;

	i = 0;
	line = NULL;
	if (buffer == NULL || buffer[i] == '\0')
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *) malloc(i + 2);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*remaining(char *buffer)
{
	char		*line;
	int			i;
	int			j;

	i = 0;
	j = 0;
	line = NULL;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = malloc(ft_strlen(buffer) - i);
	if (!line)
		return (NULL);
	i++;
	while (buffer[i] != '\0')
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}
// int main()
// {
// 	int fd;
// 	char *buff;

// 	// printf("%d\n",fd);
// 	fd = open ("example.txt", O_RDWR);
// 	buff = get_next_line(fd);
// 	// while(buff)
// 	// {
// 		printf("%s",buff);
// 	// 	free(buff);
// 	// 	buff = get_next_line(fd);
// 	// }
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// }