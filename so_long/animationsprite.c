/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animationsprite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:29:17 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/20 22:35:15 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animationup(t_data *img)
{
	if (img->a >= 90)
		img->a = 0;
	if (img->player.red == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playred.imgup[img->a / 30], img->player.x, img->player.y);
	}
	else if (img->player.blue == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playblue.imgup[img->a / 30], img->player.x, img->player.y);
	}
	else if (img->player.green == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playgreen.imgup[img->a / 30], img->player.x, img->player.y);
	}
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playwhit.imgup[img->a / 30], img->player.x, img->player.y);
}

void	animationright(t_data *img)
{
	if (img->a >= 90)
		img->a = 0;
	if (img->player.red == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playred.imgright[img->a / 30], img->player.x, img->player.y);
	}
	else if (img->player.blue == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playblue.imgright[img->a / 30], img->player.x, img->player.y);
	}
	else if (img->player.green == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playgreen.imgright[img->a / 30], img->player.x, img->player.y);
	}
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playwhit.imgright[img->a / 30], img->player.x, img->player.y);
}

void	animationleft(t_data *img)
{
	if (img->a >= 90)
		img->a = 0;
	if (img->player.red == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playred.imgleft[img->a / 30], img->player.x, img->player.y);
	}
	else if (img->player.blue == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playblue.imgleft[img->a / 30], img->player.x, img->player.y);
	}
	else if (img->player.green == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playgreen.imgleft[img->a / 30], img->player.x, img->player.y);
	}
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playwhit.imgleft[img->a / 30], img->player.x, img->player.y);
}

void	animationdown(t_data *img)
{
	if (img->a >= 90)
		img->a = 0;
	if (img->player.red == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playred.imgdown[img->a / 30], img->player.x, img->player.y);
	}
	else if (img->player.blue == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playblue.imgdown[img->a / 30], img->player.x, img->player.y);
	}
	else if (img->player.green == 1)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playgreen.imgdown[img->a / 30], img->player.x, img->player.y);
	}
	else
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->playwhit.imgdown[img->a / 30], img->player.x, img->player.y);
}
