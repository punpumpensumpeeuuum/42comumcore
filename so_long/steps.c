/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:50:40 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/21 00:53:35 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	countsteps(t_data *img)
{
	img->steepsteps++;
	ft_printf("MOVEMENTS : %d\n", img->steepsteps);
}

void	steepsteps(t_data *img)
{
	char	*movements;

	movements = ft_itoa(img->steepsteps);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->p,
		img->pixel / 4, img->pixel / 4);
	mlx_string_put(img->mlx, img->mlx_win, img->pixel / 2,
		img->pixel / 2, 0xFFFFFF, "MOVEMENTS :");
	mlx_string_put(img->mlx, img->mlx_win, 110, img->pixel / 2,
		0xFFFFFF, movements);
	free(movements);
}
