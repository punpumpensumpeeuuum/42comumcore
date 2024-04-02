/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:23:41 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/02 19:08:17 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_data *img)
{
	img->map.height = 0;
	img->map.width = 0;
	img->player.w = 0;
	img->player.a = 0;
	img->player.s = 0;
	img->player.d = 0;
	img->player.ts = 0;
	img->player.x = 500;
	img->player.y = 300;
	img->pixel = 64;
}

int	main(int argc, char **argv)
{
	argc = 0;
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 2500, 1250, "EEEEEEEEEEE");
	init(&img);
	initgame(&img, argv);
	mlx_hook(img.mlx_win, 2, 1L << 0, keypress, &img);
	mlx_hook(img.mlx_win, 3, 1L << 1, keyunpress, &img);
	mlx_loop_hook(img.mlx, andar, &img);
	mlx_loop(img.mlx);
}
