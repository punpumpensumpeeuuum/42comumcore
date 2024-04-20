/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:06:54 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/19 23:22:57 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	argmap(char **av)
{
	char	*m;
	char	*b;
	int		fd;

	b = ".ber";
	m = "map";
	if (ft_strlen(av[1]) < 4 || ft_strlen(av[1]) > 8)
		return (0);
	if (ft_strncmp(av[1], m, 3) != 0)
		return (0);
	if (av[1][4] != b[0] || av[1][5] != b[1] ||
		av[1][6] != b[2] || av[1][7] != b[3])
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}
