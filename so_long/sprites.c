/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:36:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/28 18:00:51 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprites(t_data *img)
{
	img->img = "/images/rw.xpm";
	img->imgred = "/images/red.xpm";
	img->imgblu = "/images/blue.xpm";
	img->imggrin= "/images/grin.xpm";
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
		img->player.red = 0xFF0000;
	else if (keycode == 98)
		img->player.green = 0x0000FF;
	else if (keycode == 103)
		img->player.blue = 0x00FF00;
	else if (keycode == 65362)
		img->player.w = 1;
	else if (keycode == 65361)
		img->player.a = 1;
	else if (keycode == 65363)
		img->player.s = 1;
	else if (keycode == 65364)
		img->player.d = 1;
	return (0);
}

void	movimento(t_data *img)
{
	if (img->player.w == 1)
		img->player.y --;
	if (img->player.a == 1)
		img->player.x --;
	if (img->player.s == 1)
		img->player.y ++;
	if (img->player.d == 1)
		img->player.x ++;
}

void	animation(t_data *img)
{
	if (img->player.w == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	if (img->player.a == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	if (img->player.s == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	if (img->player.d == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	if (img->player.red == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred, img->player.x, img->player.y);
	if (img->player.blue == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu, img->player.x, img->player.y);
	if (img->player.green == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin, img->player.x, img->player.y);
}

int		andar(t_data *img)
{
	movimento(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	animation(img);
	return (0);
}