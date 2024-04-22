/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whitecolision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 17:45:53 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/22 17:51:22 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

void	whitecolision(t_data *img)
{
	if (img->player.w == 1)
		colup(img);
	if (img->player.a == 1)
		colleft(img);
	if (img->player.s == 1)
		coldown(img);
	if (img->player.d == 1)
		colright(img);
}
