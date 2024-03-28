/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:23:41 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/28 18:02:50 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


// void	draw_rectangle(t_data *data, int x, int y, int width, int height, int color)
// {
// 	int i;
// 	int k;

// 	i = x;
// 	while (i < x + width)
// 	{
// 		k = y;
// 		while (k < y + height)
// 		{
// 			my_mlx_pixel_put(data, i , k, color);
// 			k++;
// 		}
// 		i++;
// 	}
	
// }

// int keychekador(int keycode, t_data *data)
// {
// 	if (keycode == 65307)
// 	{
// 		mlx_destroy_window(data->mlx, data->mlx_win);
// 		exit(0);
// 	}
// 	else if (keycode == 114)
// 		data->color = 0xFF0000;
// 	else if (keycode == 98)
// 		data->color = 0x0000FF;
// 	else if (keycode == 103)
// 		data->color = 0x00FF00;
// 	draw_rectangle(data, 0, 0, 50, 50, data->color);
// 	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
// 	return (0);
// }

// int	main(void)
// {
// 	t_data	img;

// 	img.mlx = mlx_init();
// 	img.mlx_win = mlx_new_window(img.mlx, 1080, 720, "Hello world!");
// 	img.img = mlx_new_image(img.mlx, 50, 50);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	img.color = 0xFFFFFF;
// 	draw_rectangle(&img, 0, 0, 50, 50, img.color);
// 	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
// 	mlx_key_hook(img.mlx_win, keychekador, &img);
// 	mlx_loop(img.mlx);
// }

int	main(void)
{
	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1080, 720, "Hello world!");
	sprites(&img);
	mlx_hook(img.mlx_win, 2, 1L << 0, keypress, &img);
	mlx_loop_hook(img.mlx_win, andar, &img);		
	mlx_loop(img.mlx);
}
