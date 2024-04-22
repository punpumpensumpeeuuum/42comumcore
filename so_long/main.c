/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:23:41 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/22 17:36:09 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	playerplacer(t_data *img)
{
	playerfinder(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win,
		img->playwhit.imgdown[0], img->player.x, img->player.y);
}

void	mallocmatrix(t_data *img)
{
	img->redwall = NULL;
	img->greenwall = NULL;
	img->bluewall = NULL;
	img->playwhit.imgdown = malloc(sizeof(void *) * 3);
	img->playwhit.imgleft = malloc(sizeof(void *) * 3);
	img->playwhit.imgup = malloc(sizeof(void *) * 3);
	img->playwhit.imgright = malloc(sizeof(void *) * 3);
	img->playred.imgdown = malloc(sizeof(void *) * 3);
	img->playred.imgleft = malloc(sizeof(void *) * 3);
	img->playred.imgup = malloc(sizeof(void *) * 3);
	img->playred.imgright = malloc(sizeof(void *) * 3);
	img->playgreen.imgdown = malloc(sizeof(void *) * 3);
	img->playgreen.imgleft = malloc(sizeof(void *) * 3);
	img->playgreen.imgup = malloc(sizeof(void *) * 3);
	img->playgreen.imgright = malloc(sizeof(void *) * 3);
	img->playblue.imgdown = malloc(sizeof(void *) * 3);
	img->playblue.imgleft = malloc(sizeof(void *) * 3);
	img->playblue.imgup = malloc(sizeof(void *) * 3);
	img->playblue.imgright = malloc(sizeof(void *) * 3);
}

void	initvalues(t_data *img)
{
	img->map.height = 0;
	img->map.width = 0;
	img->player.red = 0;
	img->player.green = 0;
	img->player.blue = 0;
	img->player.w = 0;
	img->player.a = 0;
	img->player.s = 0;
	img->player.d = 0;
	img->player.ts = 0;
	img->player.x = 0;
	img->player.y = 0;
	img->pixel = 64;
	img->minipixel = 32;
	img->steepsteps = 0;
	img->gamover = 0;
	img->exit = 0;
	img->count.colect = 0;
	img->count.exit = 0;
	img->count.player = 0;
	img->path.pcolect = 0;
	img->path.pexit = 0;
	img->a = 0;
	img->mlx_win = NULL;
}

void	init(t_data *img)
{
	img->playwhit.imgdown = NULL;
	img->playwhit.imgleft = NULL;
	img->playwhit.imgright = NULL;
	img->playwhit.imgup = NULL;
	img->playred.imgdown = NULL;
	img->playred.imgleft = NULL;
	img->playred.imgright = NULL;
	img->playred.imgup = NULL;
	img->playgreen.imgdown = NULL;
	img->playgreen.imgleft = NULL;
	img->playgreen.imgright = NULL;
	img->playgreen.imgup = NULL;
	img->playblue.imgdown = NULL;
	img->playblue.imgleft = NULL;
	img->playblue.imgright = NULL;
	img->playblue.imgup = NULL;
	img->imgwall = NULL;
	img->imgexit = NULL;
	img->imgcolet = NULL;
	img->mapcopy = NULL;
	img->p = NULL;
	img->imgfloor = NULL;
	img->imgenemy = NULL;
	mallocmatrix(img);
	initvalues(img);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
	{
		if (initgame(&img, argv) == 0)
			closegame(&img);
		img.mlx_win = mlx_new_window(img.mlx, img.map.width * img.pixel + \
			img.pixel * 2, img.map.height * img.pixel + img.pixel * 2, \
						"EEEEEEEEEEE");
		if (!img.mlx_win)
		{
			free(img.mlx);
			return (1);
		}
		mlx_do_key_autorepeatoff(img.mlx);
		playerplacer(&img);
		mlx_hook(img.mlx_win, 2, 1L << 0, keypress, &img);
		mlx_hook(img.mlx_win, 3, 1L << 1, keyunpress, &img);
		mlx_hook(img.mlx_win, 17, 1L << 17, closegame, &img);
		mlx_loop_hook(img.mlx, andar, &img);
		mlx_loop(img.mlx);
	}
	return (0);
}
