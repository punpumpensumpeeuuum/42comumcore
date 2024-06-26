/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:58:31 by dinis             #+#    #+#             */
/*   Updated: 2024/04/22 17:51:59 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	freemap(t_data *inf)
{
	int	i;

	i = 0;
	while (inf->mapcopy[i])
	{
		free(inf->mapcopy[i]);
		i++;
	}
	get_next_line(-1);
	free(inf->mapcopy[i]);
	free(inf->mapcopy);
}

void	checkerpather(t_data *img, int x, int y)
{
	if (!img->mapcopy || img->mapcopy[y][x] == '1' || x < 0 ||
		x >= img->map.width || y < 0 || y >= img->map.height ||
		img->mapcopy[y][x] == 'L')
		return ;
	if (img->mapcopy[y][x] == 'C')
	{
		img->path.pcolect++;
	}
	if (img->mapcopy[y][x] == 'E')
	{
		img->path.pexit++;
	}
	img->mapcopy[y][x] = '1';
	checkerpather(img, x - 1, y);
	checkerpather(img, x + 1, y);
	checkerpather(img, x, y - 1);
	checkerpather(img, x, y + 1);
}

int	checkpath(t_data *img)
{
	int	x;
	int	y;

	playerfinder(img);
	x = (img->player.x - img->pixel) / (img->pixel);
	y = (img->player.y - img->pixel) / (img->pixel);
	checkerpather(img, x, y);
	if (img->count.colect != img->path.pcolect || \
		img->count.exit != img->path.pexit)
		return (1);
	freemap(img);
	img->mapcopy = NULL;
	return (0);
}
