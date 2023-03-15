/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcullen <fcullen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 13:01:59 by fcullen           #+#    #+#             */
/*   Updated: 2023/03/15 10:17:29 by fcullen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// In get_next_line we read() text from a file into a buffer. The data in the 
// buffer is moved incrementally into a temporary variable called next_line.

// 1. Fill next_line with buffer until EOL or EOF is reached.
// 2. current_line becomes next_line
// 3. next_line becomes next line.

char	*create_current_line(char *str)
{
	char	*result;
	int		i;

	if (!str)
		return (0);
	result = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!result)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	result[i] = '\0';
	return (result);
}

char	*get_to_next(char *str)
{
	char	*result;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str[i + 1])
		return (free(str), NULL);
	i++;
	result = malloc(sizeof(char) * ft_strlen(str + i) + 1);
	if (!result)
		return (free(str), NULL);
	j = 0;
	while (str[i])
		result[j++] = str[i++];
	result[j] = '\0';
	free(str);
	return (result);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*current_line;
	static char	*next_line[2147483647];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	bytes_read = 1;
	while (!ft_strchr(next_line[fd], '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buf[bytes_read] = '\0';
		next_line[fd] = ft_strjoin(next_line[fd], buf);
	}
	free(buf);
	current_line = create_current_line(next_line[fd]);
	next_line[fd] = get_to_next(next_line[fd]);
	return (current_line);
}

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main(void)
{
	char	*temp;
	char	*temp1;
	int	fd;
	int	fd1;

	fd = open("myfile.txt", O_RDONLY);
	fd1 = open("myfile2.txt", O_RDONLY);
	while(1)
	{
		temp = get_next_line(fd);
		temp1 = get_next_line(fd1);
		if (!temp || !temp1)
			break ;
		printf("OUTPUT fd: %s\n", temp);
		printf("OUTPUT fd1: %s\n", temp1);
		free(temp);
		free(temp1);
	}
	return (0);
}