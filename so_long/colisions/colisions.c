/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:33:07 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/22 17:46:37 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	colorcolision(t_data *img)
{
	if (img->player.red == 1)
		redcolision(img);
	else if (img->player.green == 1)
		greencolision(img);
	else if (img->player.blue == 1)
		bluecolision(img);
	else
		whitecolision(img);
}
