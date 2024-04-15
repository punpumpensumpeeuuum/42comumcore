/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinis <dinis@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:10:36 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/14 19:08:19 by dinis            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	coins(t_data *img)
{
	ft_printf("%d\n", img->colectables);

	if (img->mapcopy[((img->player.y - 16) / img->pixel)][((img->player.x - 16) / img->pixel)] == 'C')
	{
		img->colectables--;
		img->mapcopy[((img->player.y - 16) / img->pixel)][((img->player.x - 16) / img->pixel)] = '0';
	}
	else if (img->mapcopy[((img->player.y - 32) / img->pixel)][((img->player.x - 32) / img->pixel)] == 'C')
	{
		img->colectables--;
		img->mapcopy[((img->player.y - 32) / img->pixel)][((img->player.x - 32) / img->pixel)] = '0';
	}
	else if (img->mapcopy[((img->player.y) / img->pixel)][((img->player.x) / img->pixel)] == 'L')
		closegame(img);
	else if (img->mapcopy[((img->player.y - 63) / img->pixel)][((img->player.x - 63) / img->pixel)] == 'L')
		closegame(img);
	else if (img->mapcopy[((img->player.y) / img->pixel)][((img->player.x) / img->pixel)] == 'E' && img->exit == 1)
		closegame(img);
	else if (img->mapcopy[((img->player.y - 63) / img->pixel)][((img->player.x - 63) / img->pixel)] == 'E' && img->exit == 1)
		closegame(img);
}
