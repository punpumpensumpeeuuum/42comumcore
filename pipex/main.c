/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/02 17:21:00 by dinda-si         ###   ########.fr       */
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

void	firstcmd(t_cmds cmds, t_fds fd, char **env, char **av)
{
	fd.fdfile[0] = open(av[1], O_RDONLY);
	if (fd.fdfile[0] == -1)
		return ;
	cmds.id1 = fork();
	if (cmds.id1 != 0)
		return ;
	dup2(fd.fdfile[0], 0);
	dup2(fd.fd[1], 1);
	close(fd.fdfile[1]);
	close(fd.fd[0]);
	if (cmds.pathcmd1 != NULL)
	{
		execve(cmds.pathcmd1, &cmds.cmd1, env);
	}
	close(fd.fdfile[0]);
	close(fd.fd[1]);
}

int	main(int ac, char **av, char **env)
{
	t_fds	fd;
	t_cmds	cmd;

	cmd.pathcmd1 = NULL;
	av[1] = ft_strjoin("./", av[1], 0);
	if (ac == 3)
	{
		cmd.pathcmd1 = checkcomand(av[2], env);
		if (cmd.pathcmd1 != NULL)
			ft_printf("%s\n", cmd.pathcmd1);
		if (pipe(fd.fd) != -1)
		{
			firstcmd(cmd, fd, env, av);
			close(fd.fd[0]);
			close(fd.fd[1]);
		}
	}
}
