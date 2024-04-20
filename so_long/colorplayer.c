/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorplayer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:15:50 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/21 00:33:25 by elemesmo         ###   ########.fr       */
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
		if (img->player.w == 1 || img->player.a == 1 || \
			img->player.s == 1 || img->player.d == 1)
			img->a++;
		if (img->player.w == 1 && img->player.s == 0)
			animationup(img);
		else if (img->player.s == 1 && img->player.w == 0)
			animationdown(img);
		else if (img->player.a == 1 && img->player.d == 0)
			animationleft(img);
		else if (img->player.d == 1 && img->player.a == 0)
			animationright(img);
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
		if (img->player.w == 1 || img->player.a == 1 || \
			img->player.s == 1 || img->player.d == 1)
			img->a++;
		if (img->player.w == 1 && img->player.s == 0)
			animationup(img);
		else if (img->player.s == 1 && img->player.w == 0)
			animationdown(img);
		else if (img->player.a == 1 && img->player.d == 0)
			animationleft(img);
		else if (img->player.d == 1 && img->player.a == 0)
			animationright(img);
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
		if (img->player.w == 1 || img->player.a == 1 || \
			img->player.s == 1 || img->player.d == 1)
			img->a++;
		if (img->player.w == 1 && img->player.s == 0)
			animationup(img);
		else if (img->player.s == 1 && img->player.w == 0)
			animationdown(img);
		else if (img->player.a == 1 && img->player.d == 0)
			animationleft(img);
		else if (img->player.d == 1 && img->player.a == 0)
			animationright(img);
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
	if (img->player.w == 1 || img->player.a == 1 || \
		img->player.s == 1 || img->player.d == 1)
		img->a++;
	if (img->player.w == 1 && img->player.s == 0)
		animationup(img);
	else if (img->player.s == 1 && img->player.w == 0)
		animationdown(img);
	else if (img->player.a == 1 && img->player.d == 0)
		animationleft(img);
	else if (img->player.d == 1 && img->player.a == 0)
		animationright(img);
	else
	{
		img->a = 0;
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playwhit.imgdown[img->a], img->player.x, img->player.y);
	}
}
