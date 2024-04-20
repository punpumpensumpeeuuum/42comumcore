/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atribuitionsprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 00:02:53 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/20 01:21:11 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	allatribuition(t_data *img)
{
	sprites(img);
	spritesplayerwhite(img);
	spritesplayerred(img);
	spritesplayerblue(img);
	spritesplayergreen(img);
}

void	spritesplayerwhite(t_data *img)
{
	img->playwhit.imgdown[0] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/p1true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgdown[1] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/p2true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgdown[2] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/p3true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgleft[0] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pe1true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgleft[1] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pe2true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgleft[2] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pe3true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgright[0] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pd1true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgright[1] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pd2true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgright[2] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pd3true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgup[0] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pt1true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgup[1] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pt2true.xpm", &img->pixel, &img->pixel);
	img->playwhit.imgup[2] = mlx_xpm_file_to_image(img->mlx,
			"images/wp/pt3true.xpm", &img->pixel, &img->pixel);
}

void	spritesplayerred(t_data *img)
{
	img->playred.imgdown[0] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/p1red.xpm", &img->pixel, &img->pixel);
	img->playred.imgdown[1] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/p2red.xpm", &img->pixel, &img->pixel);
	img->playred.imgdown[2] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/p3red.xpm", &img->pixel, &img->pixel);
	img->playred.imgleft[0] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pe1red.xpm", &img->pixel, &img->pixel);
	img->playred.imgleft[1] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pe2red.xpm", &img->pixel, &img->pixel);
	img->playred.imgleft[2] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pe3red.xpm", &img->pixel, &img->pixel);
	img->playred.imgright[0] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pd1red.xpm", &img->pixel, &img->pixel);
	img->playred.imgright[1] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pd2red.xpm", &img->pixel, &img->pixel);
	img->playred.imgright[2] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pd3red.xpm", &img->pixel, &img->pixel);
	img->playred.imgup[0] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pt1red.xpm", &img->pixel, &img->pixel);
	img->playred.imgup[1] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pt2red.xpm", &img->pixel, &img->pixel);
	img->playred.imgup[2] = mlx_xpm_file_to_image(img->mlx,
			"images/rp/pt3red.xpm", &img->pixel, &img->pixel);
}

void	spritesplayergreen(t_data *img)
{
	img->playgreen.imgdown[0] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/p1green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgdown[1] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/p2green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgdown[2] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/p3green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgleft[0] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pe1green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgleft[1] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pe2green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgleft[2] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pe3green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgright[0] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pd1green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgright[1] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pd2green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgright[2] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pd3green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgup[0] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pt1green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgup[1] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pt2green.xpm", &img->pixel, &img->pixel);
	img->playgreen.imgup[2] = mlx_xpm_file_to_image(img->mlx,
			"images/gp/pt3green.xpm", &img->pixel, &img->pixel);
}

void	spritesplayerblue(t_data *img)
{
	img->playblue.imgdown[0] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/p1blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgdown[1] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/p2blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgdown[2] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/p3blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgleft[0] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pe1blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgleft[1] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pe2blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgleft[2] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pe3blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgright[0] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pd1blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgright[1] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pd2blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgright[2] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pd3blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgup[0] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pt1blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgup[1] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pt2blue.xpm", &img->pixel, &img->pixel);
	img->playblue.imgup[2] = mlx_xpm_file_to_image(img->mlx,
			"images/bp/pt3blue.xpm", &img->pixel, &img->pixel);
}
