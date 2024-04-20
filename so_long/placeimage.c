/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeimage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:42:57 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/21 00:58:52 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	placetwo(t_data *img, int i, int j)
{
	if (img->mapcopy[i][j] == 'L')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgenemy,
			j * img->pixel + img->pixel, i * img->pixel + img->pixel);
}

void	place(t_data *img, int i, int j)
{
	if (img->mapcopy[i][j] == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgwall,
			j * img->pixel + img->pixel, i * img->pixel + img->pixel);
	else if (img->mapcopy[i][j] == '0' || img->mapcopy[i][j] == 'P')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgfloor,
			j * img->pixel + img->pixel, i * img->pixel + img->pixel);
	else if (img->mapcopy[i][j] == 'C')
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgfloor,
			j * img->pixel + img->pixel, i * img->pixel + img->pixel);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgcolet,
			j * img->pixel + img->pixel + 16, i * img->pixel + img->pixel + 16);
	}
	else if (img->mapcopy[i][j] == 'E')
	{
		if (img->exit == 0)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgfloor,
				j * img->pixel + img->pixel, i * img->pixel + img->pixel);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgexit,
				j * img->pixel + img->pixel, i * img->pixel + img->pixel);
	}
}

void	imageplacer(t_data *img, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map.height)
	{
		j = 0;
		while (j < img->map.width)
		{
			if (flag == 1)
			{
				place(img, i, j);
				j++;
			}
			if (flag == 2)
			{
				placetwo(img, i, j);
				j++;
			}
		}
		i++;
	}
}
