#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx-linux/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*imgred;
	void	*imgblu;
	void	*imggrin;
	int		pixel;
	struct s_player
	{
		int a;
		int w;
		int s;
		int d;
		int red;
		int green;
		int blue;
		int x;
		int y;
		int ts;
	}player;
}				t_data;

void	sprites(t_data *img);
int		keypress(int keycode, t_data *img);
int		keyunpress(int keycode, t_data *img);
void	movimento(t_data *img);
void	animation(t_data *img);
int 	andar(t_data *img);

void	red(t_data *img);
void	blue(t_data *img);
void	green(t_data *img);
void	white(t_data *img);


#endif