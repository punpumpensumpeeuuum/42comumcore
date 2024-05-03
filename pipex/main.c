/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/03 23:53:44 by elemesmo         ###   ########.fr       */
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

void	firstcmd(t_cmds *cmd, t_fds *fd, char **env, char **av)
{
	fd->fdfile[0] = open(av[1], O_RDONLY);
	if (fd->fdfile[0] == -1)
		return ;
	if (cmd->pathcmd1 == NULL)
	{
		ft_printf("num ha path\n");
		return ;
	}
	cmd->id1 = fork();
	if (cmd->id1 != 0)
		return ;
	else
	{
		dup2(fd->fdfile[0], 0);
		dup2(fd->fd[1], 4);
		close(fd->fd[1]);
		close(fd->fd[0]);
		close(fd->fdfile[0]);
		if (cmd->pathcmd1 != NULL)
			execve(cmd->pathcmd1, cmd->flagcmd1, env);
		exit(2);
	}
	close(fd->fdfile[0]);
	close(fd->fd[1]);
}

int	main(int ac, char **av, char **env)
{
	t_fds	fd;
	t_cmds	cmd;

	cmd.pathcmd1 = NULL;
	cmd.flagcmd1 = ft_split(av[2], ' ');
	if (ac == 3)
	{
		cmd.pathcmd1 = checkcomand(av[2], env);
		if (cmd.pathcmd1 != NULL)
			ft_printf("%s\n", cmd.pathcmd1);
		if (pipe(fd.fd) != -1)
		{
			firstcmd(&cmd, &fd, env, av);
			close(fd.fd[0]);
			close(fd.fdfile[1]);
			waitpid(cmd.id1, NULL, 0);
		}
	}
}
