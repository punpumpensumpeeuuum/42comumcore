/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:19:33 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/04 19:10:27 by dinda-si         ###   ########.fr       */
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
	int a;
	a = 0;

	i = 0;
	while (str[i] == '1' || str[i] == '0')
		i++;
	if (!(str[i] >= 0 && str[i] <= 31))
		return -1;
	return (i);
}



int	verifymapquadrado(t_data *img)
{
	int	i;
	int	row;

	row = len(img->mapcopy[0]);
	img->map.width = row;
	i = 0;
	while (img->mapcopy[i])
	{
		if (len(img->mapcopy[i]) != row)
			return (1);
		i++;
	}
	img->map.height = i;
	return (0);
}

int	initgame(t_data *img, char **argv)
{ 
	init(img);
	sprites(img);
	img->mapcopy = leromapa(argv);
	if (verifymapquadrado(img) < 0 || img->map.height <= 1 || img->map.width <= 1)
	{
		ft_printf("Map is wrong\n");
		return (0);
	}
	return (1);
}
