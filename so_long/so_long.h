#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx-linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*imgred;
	void	*imgblu;
	void	*imggrin;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
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
	}player;
}				t_data;

void	sprites(t_data *img);
int		keypress(int keycode, t_data *img);
void	movimento(t_data *img);
void	animation(t_data *img);
int 	andar(t_data *img);


#endif
