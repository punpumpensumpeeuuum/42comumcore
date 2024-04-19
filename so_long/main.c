/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:23:41 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/19 14:30:09 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	init(t_data *img)
{
	img->img = NULL;
	img->imgexit = NULL;
	img->imgred = NULL;
	img->imggrin = NULL;
	img->imgblu = NULL;
	img->imgwall = NULL;
	img->imgcolet = NULL;
	img->mapcopy = NULL;
	img->p = NULL;
	img->imgfloor = NULL;
	img->imgenemy = NULL;
	initvalues(img);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
	{
		if (initgame(&img, argv) == 0)
			exit(0);
		img.mlx_win = mlx_new_window(img.mlx, img.map.width * img.pixel + \
			img.pixel * 2, img.map.height * img.pixel + img.pixel * 2, \
						"EEEEEEEEEEE");
		if (!img.mlx_win)
		{
			free(img.mlx);
			return (1);
		}
		printf("%s", img.mapcopy[0]);
		printf("%s", img.mapcopy[1]);
		printf("%s", img.mapcopy[2]);
		printf("%s", img.mapcopy[3]);
		printf("%s", img.mapcopy[4]);
		printf("%s", img.mapcopy[5]);
		mlx_do_key_autorepeatoff(img.mlx);
		playerplacer(&img);
		// printf("%d\n", (img.player.x - img.pixel) / (img.pixel));
		// printf("%d\n", (img.player.y - img.pixel) / (img.pixel));
		mlx_hook(img.mlx_win, 2, 1L << 0, keypress, &img);
		mlx_hook(img.mlx_win, 3, 1L << 1, keyunpress, &img);
		mlx_loop_hook(img.mlx, andar, &img);
		mlx_loop(img.mlx);
	}
	return (0);
}
