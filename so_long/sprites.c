/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:36:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/01 19:11:23 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprites(t_data *img)
{
	img->img = mlx_xpm_file_to_image(img->mlx, "images/rw.xpm", &img->pixel, &img->pixel);
	img->imgred = mlx_xpm_file_to_image(img->mlx, "images/red.xpm", &img->pixel, &img->pixel);
	img->imgblu = mlx_xpm_file_to_image(img->mlx, "images/blue.xpm", &img->pixel, &img->pixel);
	img->imggrin= mlx_xpm_file_to_image(img->mlx, "images/grin.xpm", &img->pixel, &img->pixel);
}

int	keypress(int keycode, t_data *img)
{
	printf("%d\n", keycode);
	if (keycode == 65307)
	{
		mlx_destroy_window(img->mlx, img->mlx_win);
		exit(0);
	}
	else if (keycode == 114)
		img->player.red = 1;
	else if (keycode == 103)
		img->player.green = 1;
	else if (keycode == 98)
		img->player.blue = 1;
	else if (keycode == 65362 || keycode == 'w')
		img->player.w = 1;
	else if (keycode == 65361 || keycode == 'a')
		img->player.a = 1;
	else if (keycode == 65364 || keycode == 's')
		img->player.s = 1;
	else if (keycode == 65363 || keycode == 'd')
		img->player.d = 1;
	else if (keycode == 32)
		img->player.ts = 1;
	return (0);
}

int	keyunpress(int keycode, t_data *img)
{
	if (keycode == 114)
		img->player.red = 0;
	else if (keycode == 103)
		img->player.green = 0;
	else if (keycode == 98)
		img->player.blue = 0;
	else if (keycode == 65362 || keycode == 'w')
		img->player.w = 0;
	else if (keycode == 65361 || keycode == 'a')
		img->player.a = 0;
	else if (keycode == 65364 || keycode == 's')
		img->player.s = 0;
	else if (keycode == 65363 || keycode == 'd')
		img->player.d = 0;
	else if (keycode == 32)
		img->player.ts = 0;
	return (0);
}

void	movimento(t_data *img)
{
	int window_width = 2500;
	int window_height = 1250;

	if (img->player.w == 1 && img->player.y >= 0)
		img->player.y--;
	if (img->player.a == 1 && img->player.x >= 0)
		img->player.x--;
	if (img->player.s == 1 && img->player.y + img->pixel <= window_height)
		img->player.y++;
	if (img->player.d == 1 && img->player.x + img->pixel <= window_width)
		img->player.x++;
}

void	animation(t_data *img)
{
	if (img->player.red == 1)
		red(img);
	else if (img->player.blue == 1)
		blue(img);
	else if (img->player.green == 1)
		green(img);
	else
		white(img);
}

int		andar(t_data *img)
{
	movimento(img);
	if (img->player.ts == 0)
		mlx_clear_window(img->mlx, img->mlx_win);
	animation(img);
	usleep(50000 / 30);
	return (0);
}