/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greencolision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 19:29:02 by elemesmo          #+#    #+#             */
/*   Updated: 2024/04/21 20:13:21 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	greencolup(t_data *img)
{
	if (img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 9) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 62) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y - 1) / img->pixel) - 1]
		[((img->player.x - 9) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y - 1) / img->pixel) - 1][((img->player.x - 62)
		/ img->pixel)] != 'R') && (img->mapcopy[((img->player.y - 1) / \
		img->pixel) - 1][((img->player.x - 9) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y - 1) / img->pixel) - 1]
		[((img->player.x - 62) / img->pixel)] != 'B'))
		img->player.y--;
}

void	greencolleft(t_data *img)
{
	if (img->mapcopy
		[((img->player.y + 1) / img->pixel) - 1][((img->player.x + 1) / \
		img->pixel) - 1] != '1' && img->mapcopy[((img->player.y + 62) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != '1' && \
		(img->mapcopy[((img->player.y + 1) / img->pixel) - 1]
		[((img->player.x + 1) / img->pixel) - 1] != 'R' && img->mapcopy
		[((img->player.y + 62) / img->pixel) - 1][((img->player.x + 1)
		/ img->pixel) - 1] != 'R') && (img->mapcopy[((img->player.y + 1) / \
		img->pixel) - 1][((img->player.x + 1) / img->pixel) - 1] != 'B' && \
		img->mapcopy[((img->player.y + 62) / img->pixel) - 1]
		[((img->player.x + 1) / img->pixel) - 1] != 'B'))
		img->player.x--;
}

void	greencoldown(t_data *img)
{
	if (img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 9) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 62) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y + 1) / img->pixel)]
		[((img->player.x - 9) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y + 1) / img->pixel)][((img->player.x - 62)
		/ img->pixel)] != 'R') && (img->mapcopy[((img->player.y + 1) / \
		img->pixel)][((img->player.x - 9) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y + 1) / img->pixel)]
		[((img->player.x - 62) / img->pixel)] != 'B'))
		img->player.y++;
}

void	greencolright(t_data *img)
{
	if (img->mapcopy
		[((img->player.y - 1) / img->pixel)][((img->player.x + 1) / \
		img->pixel)] != '1' && img->mapcopy[((img->player.y - 62) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != '1' && \
		(img->mapcopy[((img->player.y - 1) / img->pixel)]
		[((img->player.x + 1) / img->pixel)] != 'R' && img->mapcopy
		[((img->player.y - 62) / img->pixel)][((img->player.x + 1)
		/ img->pixel)] != 'R') && (img->mapcopy[((img->player.y - 1) / \
		img->pixel)][((img->player.x + 1) / img->pixel)] != 'B' && \
		img->mapcopy[((img->player.y - 62) / img->pixel)]
		[((img->player.x + 1) / img->pixel)] != 'B'))
		img->player.x++;
}

void	greencolision(t_data *img)
{
	if (img->player.w == 1 && img->player.green == 1)
		greencolup(img);
	if (img->player.a == 1 && img->player.green == 1)
		greencolleft(img);
	if (img->player.s == 1 && img->player.green == 1)
		greencoldown(img);
	if (img->player.d == 1 && img->player.green == 1)
		greencolright(img);
}
