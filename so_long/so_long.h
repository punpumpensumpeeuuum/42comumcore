/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:52:53 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/20 00:58:46 by elemesmo         ###   ########.fr       */
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
	void	*p;
	int		a;
	struct s_white
	{
		void	**imgdown;
		void	**imgleft;
		void	**imgright;
		void	**imgup;
	}playwhit;
	struct s_red
	{
		void	**imgdown;
		void	**imgleft;
		void	**imgright;
		void	**imgup;
	}playred;
	struct s_green
	{
		void	**imgdown;
		void	**imgleft;
		void	**imgright;
		void	**imgup;
	}playgreen;
	struct s_blue
	{
		void	**imgdown;
		void	**imgleft;
		void	**imgright;
		void	**imgup;
	}playblue;
	void	**imgblu;
	void	*imgwall;
	void	*imgcolet;
	void	*imgexit;
	void	*imgfloor;
	void	*imgenemy;
	int		pixel;
	int		minipixel;
	int		exit;
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
	struct s_count
	{
		int		exit;
		int		player;
		int		colect;
	}count;
	struct s_path
	{
		int		pexit;
		int		pcolect;
	}path;
	unsigned long	steepsteps;
	int			gamover;
}				t_data;

void	init(t_data *img);
int		keypress(int keycode, t_data *img);
int		keyunpress(int keycode, t_data *img);
void	movimento(t_data *img);
void	animation(t_data *img);
int		andar(t_data *img);
void	animationdown(t_data *img);
void	animationup(t_data *img);
void	animationright(t_data *img);
void	animationleft(t_data *img);

void	closegame(t_data *img);
void	red(t_data *img);
void	blue(t_data *img);
void	green(t_data *img);
void	white(t_data *img);
void	toggle(int key, t_data *img);
void	toggle2(int key, t_data *img);

int		len(const char *str);
int		leraltura(char **argv);
char	**leromapa(char **argv);
int		initgame(t_data *img, char **argv);
int		verifymapquadrado(t_data *img);
int		verifymaponly(t_data *img);
void	mapcount(t_data *img);
void	playerfinder(t_data *img);

void	allatribuition(t_data *img);
void	sprites(t_data *img);
void	spritesplayerwhite(t_data *img);
void	spritesplayerred(t_data *img);
void	spritesplayerblue(t_data *img);
void	spritesplayergreen(t_data *img);

void	place(t_data *img, int i, int j);
void	imageplacer(t_data *img);
void	playerplacer(t_data *img);
void	countsteps(t_data *img);
void	steepsteps(t_data *img);
int		checkpath(t_data *img);

int		argmap(char **av);
void	freemap(t_data *inf);

void	coins(t_data *img);

#endif