/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecarval <jecarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:46:25 by jecarval          #+#    #+#             */
/*   Updated: 2023/05/20 14:55:26 by jecarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

char	*save_total(char *read_total, int fd)
{
	char	*read_read;
	int		rtn;

	if (!read_total)
		read_total = NULL;
	read_read = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (read_read == 0)
		free(read_read);
	rtn = BUFFER_SIZE;
	while (!ft_strchr_mod(read_total, '\n') && rtn == BUFFER_SIZE)
	{
		rtn = read(fd, read_read, BUFFER_SIZE);
		if (rtn == -1 || (rtn == 0 && read_total == NULL))
		{
			free(read_read);
			free(read_total);
			return (NULL);
		}
		read_read[rtn] = 0;
		read_total = ft_strjoin(read_total, read_read);
	}
	free(read_read);
	return (read_total);
}

char	*save_leftover(char *read_total, char *read_line)
{
	int		i;
	int		j;
	char	*leftover;

	if (!read_total || !read_line)
		return (0);
	i = ft_strlen(read_line);
	leftover = malloc((ft_strlen(read_total) - i + 1) * sizeof(char));
	if (leftover == 0)
		return (NULL);
	j = 0;
	while (read_total[j] && read_total[j] != '\n')
		j++;
	if (!read_total[j] || !read_total[j + 1])
	{
		free(leftover);
		free(read_total);
		return (NULL);
	}
	j = 0;
	while (read_total[i])
		leftover[j++] = read_total[i++];
	leftover[j] = 0;
	free(read_total);
	return (leftover);
}

char	*save_line(char *read_total)
{
	int		i;
	char	*read_line;

	i = 0;
	if (!read_total)
		return (NULL);
	read_line = malloc((ft_strlen(read_total) + 2) * sizeof(char));
	if (!read_line)
		return (NULL);
	while (read_total[i] != 0 && read_total[i] != '\n')
	{
		read_line[i] = read_total[i];
		i++;
	}
	if (read_total[i] != 0)
		read_line[i++] = '\n';
	read_line[i] = '\0';
	return (read_line);
}

char	*get_next_line(int fd)
{
	static char	*read_total[1024];
	char		*read_line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	read_total[fd] = save_total(read_total[fd], fd);
	if (!read_total[fd])
		return (0);
	read_line = save_line(read_total[fd]);
	read_total[fd] = save_leftover(read_total[fd], read_line);
	if (read_line[0] == 0)
		free(read_total[fd]);
	return (read_line);
}
/* 
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	text1;
	int	text2;
	int	i;
	char *ptrs1;
	char *ptrs2;

	text1 = open("zelda.txt", O_RDONLY);
	text2 = open("LP.txt", O_RDONLY);
	i = 0;
	while (i < 30)
	{
		ptrs1 = get_next_line(text1);
		printf ("%s", ptrs1);
		free(ptrs1);
		ptrs2 = get_next_line(text2);
		printf ("%s", ptrs2);
		free(ptrs2);
		i++;
	}	
	return (0);
}
 */
