/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:46:07 by dinda-si          #+#    #+#             */
/*   Updated: 2024/01/08 12:04:24 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str, size_t sn)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (sn == 1)
	{
		while (str[i] && str[i] != '\n')
			i++;
		return (i);
	}
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	char	*p;

	i = 0;
	if (!str1 && !str2)
		return (NULL);
	p = ft_calloc(ft_strlen(str1, 0) + ft_strlen(str2, 0) + 1, 1);
	if (!p)
		return (NULL);
	while (str1 && *str1 != '\0')
		p[i++] = *str1++;
	while (*str2 != '\n' && *str2 && str2)
		p[i++] = *str2++;
	if (*str2 == '\n')
		p[i++] = '\n';
	p[i] = '\0';
	return (p);
}

void	*ft_calloc(size_t mem, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(mem * size);
	if (!ptr)
		return (0);
	while (i < mem * size)
		ptr[i++] = '\0';
	return (ptr);
}
