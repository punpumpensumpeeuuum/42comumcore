/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:52:53 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/02 19:11:03 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "mlx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef	struct	s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*imgred;
	void	*imgblu;
	void	*imggrin;
	int		pixel;
	struct s_player
	{
		int	a;
		int	w;
		int	s;
		int	d;
		int	red;
		int	green;
		int	blue;
		int	x;
		int	y;
		int	ts;
	}player;
	char	**mapcopy;
	struct s_map
	{
		int		height;
		int		width;
	}map;
}				t_data;

void	init(t_data *img);
void	sprites(t_data *img);
int		keypress(int keycode, t_data *img);
int		keyunpress(int keycode, t_data *img);
void	movimento(t_data *img);
void	animation(t_data *img);
int		andar(t_data *img);

void	red(t_data *img);
void	blue(t_data *img);
void	green(t_data *img);
void	white(t_data *img);
void	toggle(int key, t_data *img);
void	toggle2(int key, t_data *img);

int		leraltura(char **argv);
char	**leromapa(char **argv);
int		initgame(t_data *img, char **argv);

#endif