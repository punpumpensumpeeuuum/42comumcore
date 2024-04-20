/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:10:36 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/20 22:52:14 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coins2(t_data *img)
{
	if (img->mapcopy[((img->player.y - 32) / img->pixel)][((img->player.x - 16) / img->pixel)] == 'C')
	{
		img->count.colect--;
		img->mapcopy[((img->player.y - 32) / img->pixel)][((img->player.x - 16) / img->pixel)] = '0';
	}
	else if (img->mapcopy[((img->player.y - 16) / img->pixel)][((img->player.x - 32) / img->pixel)] == 'C')
	{
		img->count.colect--;
		img->mapcopy[((img->player.y - 16) / img->pixel)][((img->player.x - 32) / img->pixel)] = '0';
	}
	else if ((img->mapcopy[((img->player.y - 50) / img->pixel)][((img->player.x - 50) / img->pixel)] == 'E' ||
	img->mapcopy[((img->player.y - 14) / img->pixel)][((img->player.x - 50) / img->pixel)] == 'E')
	&& img->exit == 1)
	{
		ft_printf("\nYou win\n\nGame over\n");
		closegame(img);
	}
	else if ((img->mapcopy[((img->player.y - 14) / img->pixel)][((img->player.x - 14) / img->pixel)] == 'E' ||
	img->mapcopy[((img->player.y - 50) / img->pixel)][((img->player.x - 14) / img->pixel)] == 'E')
	&& img->exit == 1)
	{
		ft_printf("\nYou win\n\nGame over\n");
		closegame(img);
	}
}

void	coins(t_data *img)
{
	if (img->mapcopy[((img->player.y - 16) / img->pixel)][((img->player.x - 16) / img->pixel)] == 'C')
	{
		img->count.colect--;
		img->mapcopy[((img->player.y - 16) / img->pixel)][((img->player.x - 16) / img->pixel)] = '0';
	}
	else if (img->mapcopy[((img->player.y - 32) / img->pixel)][((img->player.x - 32) / img->pixel)] == 'C')
	{
		img->count.colect--;
		img->mapcopy[((img->player.y - 32) / img->pixel)][((img->player.x - 32) / img->pixel)] = '0';
	}
	coins2(img);
	if (img->mapcopy[((img->player.y - 14) / img->pixel)][((img->player.x - 14) / img->pixel)] == 'L' ||
	img->mapcopy[((img->player.y - 50) / img->pixel)][((img->player.x - 14) / img->pixel)] == 'L')
	{
		ft_printf("\nYou dead\n\nGame over\n");
		closegame(img);
	}
	else if (img->mapcopy[((img->player.y - 50) / img->pixel)][((img->player.x - 50) / img->pixel)] == 'L' ||
	img->mapcopy[((img->player.y - 14) / img->pixel)][((img->player.x - 50) / img->pixel)] == 'L')
	{
		ft_printf("\nYou dead\n\nGame over\n");
		closegame(img);
	}
}
