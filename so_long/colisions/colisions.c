/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colisions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:33:07 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/21 20:21:17 by elemesmo         ###   ########.fr       */
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
}

void	colup(t_data *img)
{
	if (img->player.red == 1 || img->player.blue == 1 || img->player.green == 1)
		colorcolision(img);
	else if (img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 9) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 62) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y - 1) / img->pixel) - 1]
		[((img->player.x - 9) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 62)
		/ img->pixel)] != 'R') && (img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 9) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y - 1) / img->pixel) - 1]
		[((img->player.x - 62) / img->pixel)] != 'B') && (img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 9)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 62) / img->pixel)] != 'G') && \
		img->player.red == 0 && img->player.blue == 0 && img->player.green == 0)
		img->player.y--;
}

void	colleft(t_data *img)
{
	if (img->player.red == 1 || img->player.blue == 1 || img->player.green == 1)
		colorcolision(img);
	else if (img->mapcopy
		[((img->player.y + 1) / img->pixel) - 1][((img->player.x + 1) / \
		img->pixel) - 1] != '1' && img->mapcopy[((img->player.y + 62) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != '1' && \
		(img->mapcopy[((img->player.y + 1) / img->pixel) - 1]
		[((img->player.x + 1) / img->pixel) - 1] != 'R' && img->mapcopy
		[((img->player.y + 62) / img->pixel) - 1][((img->player.x + 1)
		/ img->pixel) - 1] != 'R') && (img->mapcopy[((img->player.y + 1) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != 'B' && \
		img->mapcopy[((img->player.y + 62) / img->pixel) - 1]
		[((img->player.x + 1) / img->pixel) - 1] != 'B') && (img->mapcopy
		[((img->player.y + 1) / img->pixel) - 1][((img->player.x + 1)
		/ img->pixel) - 1] != 'G' && img->mapcopy[((img->player.y + 62) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != 'G') && \
		img->player.red == 0 && img->player.blue == 0 && img->player.green == 0)
		img->player.x--;
}

void	coldown(t_data *img)
{
	if (img->player.red == 1 || img->player.blue == 1 || img->player.green == 1)
		colorcolision(img);
	else if (img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 9) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 62) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y + 1) / img->pixel)]
		[((img->player.x - 9) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 62)
		/ img->pixel)] != 'R') && (img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 9) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y + 1) / img->pixel)]
		[((img->player.x - 62) / img->pixel)] != 'B') && (img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 9)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 62) / img->pixel)] != 'G') && \
		img->player.red == 0 && img->player.blue == 0 && img->player.green == 0)
		img->player.y++;
}

void	colright(t_data *img)
{
	if (img->player.red == 1 || img->player.blue == 1 || img->player.green == 1)
		colorcolision(img);
	else if (img->mapcopy
		[((img->player.y - 1) / img->pixel)][((img->player.x + 1) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y - 62) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y - 1) / img->pixel)]
		[((img->player.x + 1) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y - 62) / img->pixel)][((img->player.x + 1)
		/ img->pixel)] != 'R') && (img->mapcopy[((img->player.y - 1) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y - 62) / img->pixel)]
		[((img->player.x + 1) / img->pixel)] != 'B') && (img->mapcopy
		[((img->player.y - 1) / img->pixel)][((img->player.x + 1)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y - 62) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != 'G') && \
		img->player.red == 0 && img->player.blue == 0 && img->player.green == 0)
		img->player.x++;
}
