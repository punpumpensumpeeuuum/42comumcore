/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinis <dinis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:36:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/15 16:37:28 by dinis            ###   ########.fr       */
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
	if (img->player.w == 1 && img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][(img->player.x / img->pixel)]
		!= '1' && img->mapcopy[((img->player.y - 1) / img->pixel) - 1]
		[((img->player.x - 62) / img->pixel)] != '1')
		img->player.y--;
	if (img->player.a == 1 && img->mapcopy
		[((img->player.y + 1) / img->pixel) - 1][((img->player.x + 1)
			/ img->pixel) - 1] != '1' && img->mapcopy[((img->player.y + 62)
			/ img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != '1')
		img->player.x--;
	if (img->player.s == 1 && img->mapcopy
		[((img->player.y + 1) / img->pixel)][(img->player.x / img->pixel)]
		!= '1' && img->mapcopy[((img->player.y + 1) / img->pixel)]
		[((img->player.x - 62) / img->pixel)] != '1')
		img->player.y++;
	if (img->player.d == 1 && img->mapcopy[((img->player.y - 1) / img->pixel)]
		[((img->player.x + 1) / img->pixel)] != '1' && img->mapcopy
		[((img->player.y - 62) / img->pixel)][((img->player.x + 1)
			/ img->pixel)] != '1')
		img->player.x++;
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
	imageplacer(img);
	animation(img);
	usleep(50000 / 30);
	if (img->count.colect == 0)
		img->exit = 1;
	return (0);
}
