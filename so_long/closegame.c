/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closegame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:37:26 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/10 15:58:05 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroyimages(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_image(img->mlx, img->imgred);
	mlx_destroy_image(img->mlx, img->imgblu);
	mlx_destroy_image(img->mlx, img->imggrin);
	mlx_destroy_image(img->mlx, img->imgwall);
	mlx_destroy_image(img->mlx, img->imgcolet);
	mlx_destroy_image(img->mlx, img->p);
	mlx_destroy_image(img->mlx, img->imgexit);
	if (img->mlx_win)
	{
		mlx_clear_window(img->mlx, img->mlx_win);
		mlx_destroy_window(img->mlx, img->mlx_win);
	}
}

void	closegame(t_data *img)
{
	int		i;

	i = 0;
	if (img->imgwall)
		destroyimages(img);
	mlx_destroy_display(img->mlx);
	free(img->mlx);
	while (img->mapcopy[i])
	{
		free(img->mapcopy[i]);
		i++;
	}
	get_next_line(123456789);
	free(img->mapcopy[i]);
	free(img->mapcopy);
	exit(0);
}
