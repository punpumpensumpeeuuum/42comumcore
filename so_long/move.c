/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:36:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/21 20:14:41 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_data *img)
{
	if (keycode == 65307)
		closegame(img);
	if (keycode == 32 || keycode == 98 || keycode == 103 || keycode == 114)
		toggle(keycode, img);
	else if (keycode == 65362 || keycode == 'w')
	{
		img->player.w = 1;
		countsteps(img);
	}
	else if (keycode == 65361 || keycode == 'a')
	{
		img->player.a = 1;
		countsteps(img);
	}
	else if (keycode == 65364 || keycode == 's')
	{
		img->player.s = 1;
		countsteps(img);
	}
	else if (keycode == 65363 || keycode == 'd')
	{
		img->player.d = 1;
		countsteps(img);
	}
	return (0);
}

int	keyunpress(int keycode, t_data *img)
{
	if (keycode == 65362 || keycode == 'w')
		img->player.w = 0;
	else if (keycode == 65361 || keycode == 'a')
		img->player.a = 0;
	else if (keycode == 65364 || keycode == 's')
		img->player.s = 0;
	else if (keycode == 65363 || keycode == 'd')
		img->player.d = 0;
	return (0);
}

void	movimento(t_data *img)
{
	if (img->player.w == 1)
		colup(img);
	if (img->player.a == 1)
		colleft(img);
	if (img->player.s == 1)
		coldown(img);
	if (img->player.d == 1)
		colright(img);
}

void	animation(t_data *img)
{
	if (img->player.red == 1)
		red(img);
	else if (img->player.green == 1)
		green(img);
	else if (img->player.blue == 1)
		blue(img);
	else
		white(img);
}

int	andar(t_data *img)
{
	// printf("x: %d\n", img->player.x);
	// printf("y: %d\n", img->player.y);
	movimento(img);
	if (img->player.ts == 0)
		mlx_clear_window(img->mlx, img->mlx_win);
	coins(img);
	steepsteps(img);
	imageplacer(img, 1);
	animation(img);
	imageplacer(img, 2);
	usleep(50000 / 30);
	if (img->count.colect == 0)
		img->exit = 1;
	return (0);
}
