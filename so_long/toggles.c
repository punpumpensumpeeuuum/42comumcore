/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:03:39 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/09 00:48:36 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	toggle(int key, t_data *img)
{
	if (key == 32)
	{
		if (img->player.ts == 1)
		{
			img->player.ts = 0;
			return ;
		}
		img->player.ts = 1;
	}
	else if (key == 114)
	{
		if (img->player.red == 1)
		{
			img->player.red = 0;
			return ;
		}
		img->player.red = 1;
	}
	else
		toggle2(key, img);
}

void	toggle2(int key, t_data *img)
{
	if (key == 103)
	{
		if (img->player.green == 1)
		{
			img->player.green = 0;
			return ;
		}
		img->player.green = 1;
	}
	else if (key == 98)
	{
		if (img->player.blue == 1)
		{
			img->player.blue = 0;
			return ;
		}
		img->player.blue = 1;
	}
}
