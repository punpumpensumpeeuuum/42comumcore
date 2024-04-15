/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinis <dinis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:23:41 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/14 19:04:48 by dinis            ###   ########.fr       */
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
	img->colectables = 0;
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
			return (0);
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
		mlx_loop_hook(img.mlx, andar, &img);
		mlx_loop(img.mlx);
	}
	return (0);
}
