/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redcolision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:29:02 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/21 20:19:11 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	redcolup(t_data *img)
{
	if (img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 9) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 62) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 9) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y - 1) / img->pixel) - 1]
		[((img->player.x - 62) / img->pixel)] != 'B') && (img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 9)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 62) / img->pixel)] != 'G'))
		img->player.y--;
}

void	redcolleft(t_data *img)
{
	if (img->mapcopy
		[((img->player.y + 1) / img->pixel) - 1][((img->player.x + 1) / \
		img->pixel) - 1] != '1' && img->mapcopy[((img->player.y + 62) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != '1' && \
		(img->mapcopy[((img->player.y + 1) / img->pixel) - 1]
		[((img->player.x + 1) / img->pixel) - 1] != 'B' && img->mapcopy
		[((img->player.y + 62) / img->pixel) - 1][((img->player.x + 1) / \
		img->pixel) - 1] != 'B') && (img->mapcopy[((img->player.y + 1) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != 'G' && \
		img->mapcopy[((img->player.y + 62) / img->pixel) - 1]
		[((img->player.x + 1) / img->pixel) - 1] != 'G'))
		img->player.x--;
}

void	redcoldown(t_data *img)
{
	if (img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 9) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 62) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 9) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y + 1) / img->pixel)]
		[((img->player.x - 62) / img->pixel)] != 'B') && (img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 9)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 62) / img->pixel)] != 'G'))
		img->player.y++;
}

void	redcolright(t_data *img)
{
	if (img->mapcopy
		[((img->player.y - 1) / img->pixel)][((img->player.x + 1) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y - 62) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y - 1) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y - 62) / img->pixel)]
		[((img->player.x + 1) / img->pixel)] != 'B') && (img->mapcopy
		[((img->player.y - 1) / img->pixel)][((img->player.x + 1)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y - 62) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != 'G'))
		img->player.x++;
}

void	redcolision(t_data *img)
{
	if (img->player.w == 1 && img->player.red == 1)
		redcolup(img);
	if (img->player.a == 1 && img->player.red == 1)
		redcolleft(img);
	if (img->player.s == 1 && img->player.red == 1)
		redcoldown(img);
	if (img->player.d == 1 && img->player.red == 1)
		redcolright(img);
}
