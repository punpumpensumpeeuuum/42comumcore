/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placeimage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinis <dinis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:42:57 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/14 19:02:06 by dinis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place(t_data *img, int i, int j)
{
	if (img->mapcopy[i][j] == '1')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgwall,
			j * img->pixel + img->pixel, i * img->pixel + img->pixel);
	else if (img->mapcopy[i][j] == 'C')
	{	
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgfloor,
			j * img->pixel + img->pixel, i * img->pixel + img->pixel);
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgcolet,
			j * img->pixel + img->pixel + 16, i * img->pixel + img->pixel + 16);
	}
	else if (img->mapcopy[i][j] == 'L')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgenemy,
			j * img->pixel + img->pixel, i * img->pixel + img->pixel);
	else if (img->mapcopy[i][j] == 'E')
	{
		if (img->exit == 0)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgfloor,
				j * img->pixel + img->pixel, i * img->pixel + img->pixel);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgexit,
				j * img->pixel + img->pixel, i * img->pixel + img->pixel);
	}
	else if (img->mapcopy[i][j] == '0' || img->mapcopy[i][j] == 'P')
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgfloor,
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

void	countsteps(t_data *img)
{
	img->steepsteps++;
	ft_printf("MOVEMENTS : %d\n", img->steepsteps);
}

void	steepsteps(t_data *img)
{
	char	*movements;

	movements = ft_itoa(img->steepsteps);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->p, img->pixel / 4, img->pixel / 4);
	mlx_string_put(img->mlx, img->mlx_win, img->pixel / 2, img->pixel / 2, 0xFFFFFF, "MOVEMENTS :");
	mlx_string_put(img->mlx, img->mlx_win, 110, img->pixel / 2, 0xFFFFFF, movements);
	free(movements);
}
