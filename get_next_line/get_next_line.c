/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:41:55 by dinda-si          #+#    #+#             */
/*   Updated: 2023/11/28 17:40:58 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char *str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(str, buffer);
	free(str);
	return (temp);
}

void	bufferclean(char *buffer)
{
	char	*temp;
	int		i;

	if (!buffer)
		return ;
	i = 0;
	temp = buffer;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		buffer[i++] = '\0';
	if (buffer[i] == '\n')
		buffer[i++] = '\0';
	while (buffer[i] != '\0')
	{
		*temp = buffer[i];
		temp++;
		buffer[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;

	str = NULL;
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (0);
	}
	if (!buffer)
		buffer = ft_calloc(BUFFER_SIZE + 1, 1);
	str = ft_joinfree(str, buffer);
	bufferclean(buffer);
	while (str && !(str[ft_strlen(str, 1)] == '\n') && read(fd, buffer,
			BUFFER_SIZE) && BUFFER_SIZE > 0)
	{
		str = ft_joinfree(str, buffer);
		bufferclean(buffer);
	}
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	fd = open("ddddddd", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("ola: %s\n", s);
// 	free(s);
// 	s = get_next_line(fd);
// 	printf("ola: %s\n", s);
// 	free(s);
// 	get_next_line(-1);
// }
