/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/30 18:08:41 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*checkcomand(char *cmd, char **env)
{
	int i;
	char *path;
	char **paths;

	i = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_split(env[i] + 5, ':');
			i = 0;
			while (paths[i])
			{
				path = ft_strjoin(paths[i], cmd);
				ft_printf("%s\n", path);
				if (!(access(path, X_OK)))
					return ("ola");
				i++;
			}
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
	if (ac == 2)
	{
		ft_printf("%s\n",checkcomand(av[1], env));
		path = checkcomand(av[1], env);
		// if (path != NULL)
		// 	ft_printf("%s\n", path);
		i++;
		return 0;
	}
}
