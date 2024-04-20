/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:15:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/20 01:22:23 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sprites(t_data *img)
{
	int	larg;

	larg = img->pixel * 3;
	img->imgwall = mlx_xpm_file_to_image(img->mlx, "images/parede.xpm",
			&img->pixel, &img->pixel);
	// img->img = mlx_xpm_file_to_image(img->mlx, "images/wp/p1true.xpm",
	// 		&img->pixel, &img->pixel);
	// img->imgred = mlx_xpm_file_to_image(img->mlx, "images/rp/p1red.xpm",
	// 		&img->pixel, &img->pixel);
	// img->imgblu = mlx_xpm_file_to_image(img->mlx, "images/bp/p1blue.xpm",
	// 		&img->pixel, &img->pixel);
	// img->imggrin = mlx_xpm_file_to_image(img->mlx, "images/gp/p1green.xpm",
	// 		&img->pixel, &img->pixel);
	img->imgcolet = mlx_xpm_file_to_image(img->mlx, "images/cole.xpm",
			&img->minipixel, &img->minipixel);
	img->imgexit = mlx_xpm_file_to_image(img->mlx, "images/m.xpm",
			&img->pixel, &img->pixel);
	img->p = mlx_xpm_file_to_image(img->mlx, "images/p.xpm",
			&larg, &img->pixel);
	img->imgfloor = mlx_xpm_file_to_image(img->mlx, "images/floor.xpm",
			&img->pixel, &img->pixel);
	img->imgenemy = mlx_xpm_file_to_image(img->mlx, "images/enemy.xpm",
			&img->pixel, &img->pixel);
}

void	red(t_data *img)
{
	if (img->player.red == 1)
	{
		if (img->player.w == 1)
			animationup(img);
		if (img->player.a == 1)
			animationleft(img);
		if (img->player.s == 1)
			animationdown(img);
		if (img->player.d == 1)
			animationright(img);
		if (img->player.w == 1 || img->player.a == 1 || \
			img->player.s == 1 || img->player.d == 1)
			img->a++;
		else
		{
			img->a = 0;
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->playred.imgdown[img->a], img->player.x, img->player.y);
		}
	}
}

void	blue(t_data *img)
{
	if (img->player.blue == 1)
	{
		if (img->player.w == 1)
			animationup(img);
		if (img->player.a == 1)
			animationleft(img);
		if (img->player.s == 1)
			animationdown(img);
		if (img->player.d == 1)
			animationright(img);
		if (img->player.w == 1 || img->player.a == 1 || \
			img->player.s == 1 || img->player.d == 1)
			img->a++;
		else
		{
			img->a = 0;
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->playblue.imgdown[img->a], img->player.x, img->player.y);
		}
	}
}

void	green(t_data *img)
{
	if (img->player.green == 1)
	{
		if (img->player.w == 1)
			animationup(img);
		if (img->player.a == 1)
			animationleft(img);
		if (img->player.s == 1)
			animationdown(img);
		if (img->player.d == 1)
			animationright(img);
		if (img->player.w == 1 || img->player.a == 1 || \
			img->player.s == 1 || img->player.d == 1)
			img->a++;
		else
		{
			img->a = 0;
			mlx_put_image_to_window(img->mlx, img->mlx_win,
				img->playgreen.imgdown[img->a], img->player.x, img->player.y);
		}
	}
}

void	white(t_data *img)
{
	if (img->player.w == 1)
		animationup(img);
	if (img->player.a == 1)
		animationleft(img);
	if (img->player.s == 1)
		animationdown(img);
	if (img->player.d == 1)
		animationright(img);
	if (img->player.w == 1 || img->player.a == 1 || \
		img->player.s == 1 || img->player.d == 1)
		img->a++;
	else
	{
		img->a = 0;
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playwhit.imgdown[img->a], img->player.x, img->player.y);
	}
}
