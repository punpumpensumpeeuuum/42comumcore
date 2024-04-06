/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:36:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/06 04:36:26 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress(int keycode, t_data *img)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	else if (keycode == 65362 || keycode == 'w')
		img->player.w = 1;
	else if (keycode == 65361 || keycode == 'a')
		img->player.a = 1;
	else if (keycode == 65364 || keycode == 's')
		img->player.s = 1;
	else if (keycode == 65363 || keycode == 'd')
		img->player.d = 1;
	else if (keycode == 32 || keycode == 98 || keycode == 103 || keycode == 114)
		toggle(keycode, img);
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
	if (img->player.w == 1 && img->player.y - img->pixel >= 0)
		img->player.y--;
	if (img->player.a == 1 && img->player.x - img->pixel >= 0)
		img->player.x--;
	if (img->player.s == 1 && img->player.y <= img->map.height * img->pixel)
		img->player.y++;
	if (img->player.d == 1 && img->player.x <= img->map.width * img->pixel)
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
	movimento(img);
	if (img->player.ts == 0)
		mlx_clear_window(img->mlx, img->mlx_win);
	animation(img);
	imageplacer(img);
	usleep(50000 / 30);
	return (0);
}
