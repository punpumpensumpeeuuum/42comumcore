/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:19:33 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/03 19:06:10 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	leraltura(char **argv)
{
	int		fd;
	char	*temp;
	int		altura;

	fd = open(argv[1], O_RDONLY);
	temp = get_next_line(fd);
	altura = 0;
	while (temp)
	{
		free(temp);
		temp = get_next_line(fd);
		altura++;
	}
	free(temp);
	close(fd);
	return (altura);
}

char	**leromapa(char **argv)
{
	char	**map;
	int		fd;
	char	*temp;
	int		a;
	int		alt;

	fd = open(argv[1], O_RDONLY);
	alt = leraltura(argv);
	map = malloc(sizeof(char *) * alt + 1);
	temp = get_next_line(-1);
	a = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		map[a] = temp;
		temp = get_next_line(fd);
		a++;
	}
	map[a] = NULL;
	free(temp);
	close(fd);
	return (map);
}

int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
int	verifymapquadrado(t_data *img)
{
	int i;

	i = len(img->mapcopy[img->map.height]);
	while (img->mapcopy[img->map.width])
	{
		if (len(img->mapcopy[img->map.width]) != i)
			return (0);
		img->mapcopy[img->map.width]++;	
	}
	return (0);
}

int	initgame(t_data *img, char **argv)
{
	init(img);
	sprites(img);
	img->mapcopy = leromapa(argv);
	verifymapquadrado(img);
	return (0);
}
