/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closegame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:37:26 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/20 01:27:12 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroymatrix(t_data *img);

void	destroyimages(t_data *img)
{
	// mlx_destroy_image(img->mlx, img->img);
	// mlx_destroy_image(img->mlx, img->imgred);
	// mlx_destroy_image(img->mlx, img->imgblu);
	// mlx_destroy_image(img->mlx, img->imggrin);
	mlx_destroy_image(img->mlx, img->imgwall);
	mlx_destroy_image(img->mlx, img->imgcolet);
	mlx_destroy_image(img->mlx, img->p);
	mlx_destroy_image(img->mlx, img->imgexit);
	mlx_destroy_image(img->mlx, img->imgfloor);
	mlx_destroy_image(img->mlx, img->imgenemy);
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
