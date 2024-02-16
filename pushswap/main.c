// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/01/31 14:17:24 by dinda-si          #+#    #+#             */
// /*   Updated: 2024/01/31 15:17:48 by dinda-si         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "pushswap.h"

// int	main(int argc, char **argv)
// {
// 	int i = 1;
// 	int j = 0;

// 	if (argc < 2)
// 	{
// 		write(1, "Error\n", 6);
// 		return(0);
// 	}
// 	while (argv[i])
// 	{
// 		while (argv[i][j])
// 		{
// 			if ((argv[i][j] < 48 || argv[i][j] > 57) && argv[i][j] && argv[i][j] != 45)
// 			{
// 				write(1, "Error\n", 6);
// 				return (0);
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// 	i = 1;
// 	while (argv[i])
// 	{
// 		while (argv[i][j])
// 			write(1, &argv[i][j++], 1);
// 		if (argv[i + 1])
// 			write(1, " ", 1);
// 		j = 0;
// 		i++;
// 	}
// }