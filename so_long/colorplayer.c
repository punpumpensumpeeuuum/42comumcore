/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:15:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/01 19:00:03 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	red(t_data *img)
{
	if (img->player.red == 1)
	{
		if (img->player.w == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred, img->player.x, img->player.y);
		if (img->player.a == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred, img->player.x, img->player.y);
		if (img->player.s == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred, img->player.x, img->player.y);
		if (img->player.d == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred, img->player.x, img->player.y);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgred, img->player.x, img->player.y);
	}
}

void	blue(t_data *img)
{
	if (img->player.blue == 1)
	{
		if (img->player.w == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu, img->player.x, img->player.y);
		if (img->player.a == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu, img->player.x, img->player.y);
		if (img->player.s == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu, img->player.x, img->player.y);
		if (img->player.d == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu, img->player.x, img->player.y);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imgblu, img->player.x, img->player.y);
	}
}

void	green(t_data *img)
{
	if (img->player.green == 1)
	{
		if (img->player.w == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin, img->player.x, img->player.y);
		if (img->player.a == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin, img->player.x, img->player.y);
		if (img->player.s == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin, img->player.x, img->player.y);
		if (img->player.d == 1)
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin, img->player.x, img->player.y);
		else
			mlx_put_image_to_window(img->mlx, img->mlx_win, img->imggrin, img->player.x, img->player.y);
	}
}

void	white(t_data *img)
{
	if (img->player.w == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	if (img->player.a == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	if (img->player.s == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	if (img->player.d == 1)
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, img->player.x, img->player.y);
}
