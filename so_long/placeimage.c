/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeimage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:42:57 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/08 02:03:52 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place(t_data *img, int i, int j)
{
	if (img->mapcopy[i][j] == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgwall,
			j * img->pixel + img->pixel, i * img->pixel + img->pixel);
}

void	imageplacer(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map.height)
	{
		j = 0;
		while (j < img->map.width)
		{
			place(img, i, j);
			j++;
		}
		i++;
	}
}

void	playerplacer(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map.height)
	{
		j = 0;
		while (j < img->map.width)
		{
			if (img->mapcopy[i][j] == 'P')
			{
				img->player.x = (j * img->pixel) + (img->pixel);
				img->player.y = (i * img->pixel) + (img->pixel);
				mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
					img->player.x, img->player.y);
			}
			j++;
		}
		i++;
	}
}
