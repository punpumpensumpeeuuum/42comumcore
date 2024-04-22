/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:19:33 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/22 17:43:59 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
		ft_printf("Error\n\nNo map?\n");
		exit(0);
	}
	img->mlx = mlx_init();
	init(img);
	allatribuition(img);
	img->mapcopy = leromapa(argv);
	if (img->mapcopy == NULL)
		return (0);
	mapcount(img);
	if (verifymapquadrado(img) != 0 || img->map.height < 3
		|| img->map.width < 3 || verifymaponly(img) != 0 || \
		img->count.player != 1 || img->count.exit != 1 || \
		img->count.colect < 1 || checkpath(img) != 0)
	{
		ft_printf("Error\n\nMap is wrong\n");
		return (0);
	}
	img->mapcopy = leromapa(argv);
	if (img->mapcopy == NULL)
		return (0);
	return (1);
}
