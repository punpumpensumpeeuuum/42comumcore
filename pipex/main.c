/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/02 03:33:09 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*checkcomand(char *cmd, char **env)
{
	int		i;
	int		p;
	char	*path;
	char	**paths;

	i = 0;
	p = 0;
	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			paths = ft_split(env[i] + 5, ':');
			p = 0;
			while (paths[p++])
			{
				path = ft_strjoin(paths[p], cmd, 1);
				if (access(path, X_OK) == 0)
					return (path);
			}
		}
		i++;
	}
	path = NULL;
	return (path);
}

void	firstcmd(char *path, t_fds fd, char **env)
{
	int	id;

	id = fork();
	if (id != 0)
		return ;
	dup2(fd.fd2[0], 0);
	dup2(fd.fd[1], 1);
}

int	main(int ac, char **av, char **env)
{
	t_fds	fd;
	char	*path;

	path = NULL;
	if (ac == 3)
	{
		path = checkcomand(av[2], env);
		if (path != NULL)
			ft_printf("%s\n", path);
		if (pipe(fd.fd) != -1)
		{
			fd.fd2[0] = open(av[1], O_RDONLY);
			if (fd.fd2[0] == -1)
				return (-1);
			firstcmd(path, fd, env);
			close(fd.fd[0]);
			close(fd.fd[1]);
		}
	}
}
