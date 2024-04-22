/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closegame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:37:26 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/22 17:44:07 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroymatrix(t_data *img)
{
	img->a = 0;
	while (img->a < 3)
	{
		mlx_destroy_image(img->mlx, img->playwhit.imgdown[img->a]);
		mlx_destroy_image(img->mlx, img->playwhit.imgup[img->a]);
		mlx_destroy_image(img->mlx, img->playwhit.imgright[img->a]);
		mlx_destroy_image(img->mlx, img->playwhit.imgleft[img->a]);
		mlx_destroy_image(img->mlx, img->playred.imgdown[img->a]);
		mlx_destroy_image(img->mlx, img->playred.imgup[img->a]);
		mlx_destroy_image(img->mlx, img->playred.imgright[img->a]);
		mlx_destroy_image(img->mlx, img->playred.imgleft[img->a]);
		mlx_destroy_image(img->mlx, img->playblue.imgdown[img->a]);
		mlx_destroy_image(img->mlx, img->playblue.imgup[img->a]);
		mlx_destroy_image(img->mlx, img->playblue.imgright[img->a]);
		mlx_destroy_image(img->mlx, img->playblue.imgleft[img->a]);
		mlx_destroy_image(img->mlx, img->playgreen.imgdown[img->a]);
		mlx_destroy_image(img->mlx, img->playgreen.imgup[img->a]);
		mlx_destroy_image(img->mlx, img->playgreen.imgright[img->a]);
		mlx_destroy_image(img->mlx, img->playgreen.imgleft[img->a]);
		img->a++;
	}
}

void	freeplayer(t_data *img)
{
	free(img->playwhit.imgdown);
	free(img->playwhit.imgup);
	free(img->playwhit.imgright);
	free(img->playwhit.imgleft);
	free(img->playred.imgdown);
	free(img->playred.imgup);
	free(img->playred.imgright);
	free(img->playred.imgleft);
	free(img->playblue.imgdown);
	free(img->playblue.imgup);
	free(img->playblue.imgright);
	free(img->playblue.imgleft);
	free(img->playgreen.imgdown);
	free(img->playgreen.imgup);
	free(img->playgreen.imgright);
	free(img->playgreen.imgleft);
}

void	destroyimages(t_data *img)
{
	destroymatrix(img);
	freeplayer(img);
	mlx_destroy_image(img->mlx, img->imgwall);
	mlx_destroy_image(img->mlx, img->redwall);
	mlx_destroy_image(img->mlx, img->greenwall);
	mlx_destroy_image(img->mlx, img->bluewall);
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

int	closegame(t_data *img)
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
	get_next_line(-1);
	free(img->mapcopy[i]);
	free(img->mapcopy);
	exit(0);
}
