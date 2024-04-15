/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinis <dinis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:19:33 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/14 19:04:19 by dinis            ###   ########.fr       */
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
	if (fd <= 1)
		return (NULL);
	alt = leraltura(argv);
	map = malloc(sizeof(char *) * (alt + 1));
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

int	initgame(t_data *img, char **argv)
{
	if (argmap(argv) == 0)
	{	
		printf("No map?\n");
		exit(0);
	}
	img->mlx = mlx_init();
	init(img);
	sprites(img);
	img->mapcopy = leromapa(argv);
	if (img->mapcopy == NULL)
		return (0);
	if (verifymapquadrado(img) != 0 || img->map.height <= 1
		|| img->map.width <= 1 || verifymaponly(img) != 0)
	{
		ft_printf("Map is wrong\n");
		return (0);
	}
	return (1);
}
