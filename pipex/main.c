/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/26 18:23:21 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*checkcomand(char **env)
{
	int i;
	char **paths;
	char *path;

	i = 0;
	path = NULL;
	paths = NULL;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{	
			path = env[i];
			paths = ft_split(env[i], ':');
		}
		i++;
	}
	return (path);
}

int main(int ac, char **av, char **env)
{
	int i;
	char *path;

	path = NULL;
	i = 0;
	if (ac == 2 && av[1])
	{
		path = checkcomand(env);
		if (path != NULL)
			ft_printf("%s\n", path);
		i++;
		return 0;
	}
}
