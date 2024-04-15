/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapverify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinis <dinis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:12:31 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/15 16:29:06 by dinis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '1' || str[i] == '0' || str[i] == 'P' || str[i] == 'C' || str[i] == 'E' || str[i] == 'L')
		i++;
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

int	verifymaponly(t_data *img)
{
	int	h;
	int	w;

	w = 0;
	h = 0;
	while (w < img->map.width)
	{
		if (img->mapcopy[h][w++] != '1')
			return (1);
	}
	while (h < img->map.height)
	{
		if (img->mapcopy[h][0] != '1' ||
			img->mapcopy[h][img->map.width - 1] != '1')
			return (1);
		h++;
	}
	h--;
	w = 0;
	while (w < img->map.width)
	{
		if (img->mapcopy[h][w++] != '1')
			return (1);
	}
	return (0);
}

void	mapcount(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->mapcopy[i])
	{
		j = 0;
		while (img->mapcopy[i][j])
		{
			if (img->mapcopy[i][j] == 'P')
				img->count.player++;
			if (img->mapcopy[i][j] == 'E')
				img->count.exit++;
			if (img->mapcopy[i][j] == 'C')
				img->count.colect++;
			j++;
		}
		i++;
	}
}
