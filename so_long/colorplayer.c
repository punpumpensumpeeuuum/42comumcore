/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:15:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/10 18:20:35 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprites(t_data *img)
{
	int larg;

	larg = img->pixel * 3;
	img->imgwall = mlx_xpm_file_to_image(img->mlx, "images/parede.xpm",
			&img->pixel, &img->pixel);
	img->img = mlx_xpm_file_to_image(img->mlx, "images/rw.xpm",
			&img->pixel, &img->pixel);
	img->imgred = mlx_xpm_file_to_image(img->mlx, "images/red.xpm",
			&img->pixel, &img->pixel);
	img->imgblu = mlx_xpm_file_to_image(img->mlx, "images/blue.xpm",
			&img->pixel, &img->pixel);
	img->imggrin = mlx_xpm_file_to_image(img->mlx, "images/grin.xpm",
			&img->pixel, &img->pixel);
	img->imgcolet = mlx_xpm_file_to_image(img->mlx, "images/col.xpm",
			&img->minipixel, &img->minipixel);
	img->imgexit = mlx_xpm_file_to_image(img->mlx, "images/m.xpm",
			&img->pixel, &img->pixel);
	img->p = mlx_xpm_file_to_image(img->mlx, "images/p.xpm",
			&larg, &img->pixel);
	img->imgfloor = mlx_xpm_file_to_image(img->mlx, "images/floor.xpm",
			&img->pixel, &img->pixel);
}

void	red(t_data *img)
{
	if (img->player.red == 1)
	{
		if (img->player.w == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred,
				img->player.x, img->player.y);
		if (img->player.a == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred,
				img->player.x, img->player.y);
		if (img->player.s == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred,
				img->player.x, img->player.y);
		if (img->player.d == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred,
				img->player.x, img->player.y);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred,
				img->player.x, img->player.y);
	}
}

void	blue(t_data *img)
{
	if (img->player.blue == 1)
	{
		if (img->player.w == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu,
				img->player.x, img->player.y);
		if (img->player.a == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu,
				img->player.x, img->player.y);
		if (img->player.s == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu,
				img->player.x, img->player.y);
		if (img->player.d == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu,
				img->player.x, img->player.y);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu,
				img->player.x, img->player.y);
	}
}

void	green(t_data *img)
{
	if (img->player.green == 1)
	{
		if (img->player.w == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin,
				img->player.x, img->player.y);
		if (img->player.a == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin,
				img->player.x, img->player.y);
		if (img->player.s == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin,
				img->player.x, img->player.y);
		if (img->player.d == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin,
				img->player.x, img->player.y);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin,
				img->player.x, img->player.y);
	}
}

void	white(t_data *img)
{
	if (img->player.w == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			img->player.x, img->player.y);
	if (img->player.a == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			img->player.x, img->player.y);
	if (img->player.s == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			img->player.x, img->player.y);
	if (img->player.d == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			img->player.x, img->player.y);
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img,
			img->player.x, img->player.y);
}
