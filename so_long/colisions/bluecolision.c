/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bluecolision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:29:02 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/21 20:13:24 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	bluecolup(t_data *img)
{
	if (img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 9) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 62) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y - 1) / img->pixel) - 1]
		[((img->player.x - 9) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 62)
		/ img->pixel)] != 'R') && (img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 9)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 62) / img->pixel)] != 'G'))
		img->player.y--;
}

void	bluecolleft(t_data *img)
{
	if (img->mapcopy
		[((img->player.y + 1) / img->pixel) - 1][((img->player.x + 1) / \
		img->pixel) - 1] != '1' && img->mapcopy[((img->player.y + 62) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != '1' && \
		(img->mapcopy[((img->player.y + 1) / img->pixel) - 1]
		[((img->player.x + 1) / img->pixel) - 1] != 'R' && img->mapcopy
		[((img->player.y + 62) / img->pixel) - 1][((img->player.x + 1)
		/ img->pixel) - 1] != 'R') && (img->mapcopy
		[((img->player.y + 1) / img->pixel) - 1][((img->player.x + 1)
		/ img->pixel) - 1] != 'G' && img->mapcopy[((img->player.y + 62) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != 'G'))
		img->player.x--;
}

void	bluecoldown(t_data *img)
{
	if (img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 9) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 62) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y + 1) / img->pixel)]
		[((img->player.x - 9) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 62)
		/ img->pixel)] != 'R') && (img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 9)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 62) / img->pixel)] != 'G'))
		img->player.y++;
}

void	bluecolright(t_data *img)
{
	if (img->mapcopy
		[((img->player.y - 1) / img->pixel)][((img->player.x + 1) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y - 62) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y - 1) / img->pixel)]
		[((img->player.x + 1) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y - 62) / img->pixel)][((img->player.x + 1)
		/ img->pixel)] != 'R') && (img->mapcopy
		[((img->player.y - 1) / img->pixel)][((img->player.x + 1)
		/ img->pixel)] != 'G' && img->mapcopy[((img->player.y - 62) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != 'G'))
		img->player.x++;
}

void	bluecolision(t_data *img)
{
	if (img->player.w == 1 && img->player.blue == 1)
		bluecolup(img);
	if (img->player.a == 1 && img->player.blue == 1)
		bluecolleft(img);
	if (img->player.s == 1 && img->player.blue == 1)
		bluecoldown(img);
	if (img->player.d == 1 && img->player.blue == 1)
		bluecolright(img);
}
