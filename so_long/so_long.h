/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:52:53 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/09 00:09:52 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx-linux/mlx.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*imgred;
	void	*imgblu;
	void	*imggrin;
	void	*imgwall;
	void	*imgcolet;
	int		pixel;
	int		minipixel;
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
int		verifymapquadrado(t_data *img);
int		verifymaponly(t_data *img);

void	place(t_data *img, int i, int j);
void	imageplacer(t_data *img);
void	playerplacer(t_data *img);

#endif