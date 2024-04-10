/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapverify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:12:31 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/10 17:15:37 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '1' || str[i] == '0' || str[i] == 'P' || str[i] == 'C' || str[i] == 'E')
		i++;
	if (!(str[i] >= 0 && str[i] <= 31))
		return (-1);
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
