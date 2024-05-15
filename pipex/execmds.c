/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:11:26 by elemesmo          #+#    #+#             */
/*   Updated: 2024/05/15 01:34:33 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	checkhelp(char *comand, char **env, int i, t_cmds *cmd)
{
	int	p;

	while (env && env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			cmd->minipaths = ft_split(env[i] + 5, ':');
			p = 0;
			while (cmd->minipaths[p])
			{
				cmd->minipath = ft_strjoin(cmd->minipaths[p], comand, 1);
				if (access(cmd->minipath, X_OK) == 0)
				{
					freepaths(cmd->minipaths, i);
					return ;
				}
				free(cmd->minipath);
				cmd->minipath = NULL;
				p++;
			}
		}
		i++;
	}
	return ;
}

int	piping(t_cmds *cmd, t_fds *fd, char **env, char **av)
{
	if (cmd->p == 0)
	{
		ft_printf("first\n");
		firstcmd(cmd, fd, env, av);
		if (cmd->id1 == 0)
			return (1);
	}
	if (cmd->p != 0 && cmd->i < cmd->ac)
	{
		ft_printf("mid\n");
		midcmd(cmd, fd, env);
		if (cmd->id2 == 0)
			return (2);
	}
	if (cmd->i == cmd->ac)
	{
		ft_printf("last\n");
		lastcmd(cmd, fd, env, av);
		close(fd->fd[cmd->p - 1]);
		if (cmd->id3 == 0)
			return (3);
	}
	cmd->i++;
	return (0);
}

void	firstcmd(t_cmds *cmd, t_fds *fd, char **env, char **av)
{
	fd->fdfile[0] = open(av[1], O_RDONLY);
	if (fd->fdfile[0] == -1)
		return ;
	if (ft_strncmp(cmd->pathstodos[cmd->i], "error", 5) == 0)
	{
		ft_printf("first num ha path\n");
		return ;
	}
	cmd->id1 = fork();
	if (cmd->id1 != 0)
		return ;
	else
	{
		dup2(fd->fdfile[0], 0);
		dup2(fd->fd[cmd->p + 1], 1);
		close(fd->fd[cmd->p]);
		close(fd->fd[cmd->p + 1]);
		close(fd->fdfile[0]);
		execve(cmd->pathstodos[cmd->i], cmd->flagtodos[cmd->i], env);
		exit(1);
	}
	close(fd->fdfile[0]);
	close(fd->fd[cmd->p + 1]);
}

void	midcmd(t_cmds *cmd, t_fds *fd, char **env)
{
	if (ft_strncmp(cmd->pathstodos[cmd->i], "error", 5) == 0)
	{
		ft_printf("mid num ha path\n");
		return ;
	}
	cmd->id2 = fork();
	if (cmd->id2 != 0)
		return ;
	else
	{
		// ft_printf(" %s\n", cmd->flagtodos[cmd->i][1]);
		// ft_printf("dup 2: %d\n", fd->fd[2 * cmd->p + 1]);
		// ft_printf("close 1: %d\n", fd->fd[2 * (cmd->p - 1) + 1]);
		// ft_printf("close 2: %d\n", fd->fd[2 * cmd->p + 1]);
		dup2(fd->fd[2 * (cmd->p - 1)], 0);
		dup2(fd->fd[2 * cmd->p + 1], 1);
		close(fd->fd[2 * (cmd->p - 1) + 1]);
		close(fd->fd[2 * cmd->p + 1]);
		execve(cmd->pathstodos[cmd->i], cmd->flagtodos[cmd->i], env);
		exit(2);
	}
	close(fd->fd[2 * (cmd->p - 1)]);
	close(fd->fd[2 * cmd->p + 1] + 1);
}

void	lastcmd(t_cmds *cmd, t_fds *fd, char **env, char **av)
{
	fd->fdfile[1] = open(av[cmd->ac + 3], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd->fdfile[1] == -1)
		return ;
	if (ft_strncmp(cmd->pathstodos[cmd->i], "error", 5) == 0)
	{
		ft_printf("last num ha path\n");
		return ;
	}
	cmd->id3 = fork();
	if (cmd->id3 != 0)
		return ;
	else
	{
		ft_printf("lst=%s\n", cmd->flagtodos[cmd->i][1]);
		// ft_printf("dup 2: %d\n", fd->fd[2 * (cmd->p - 1)]);
		// ft_printf("close 1: %d\n", fd->fd[2 * (cmd->p - 1)]);
		// ft_printf("close 2: %d\n", fd->fd[2 * (cmd->p - 1) + 1]);
		dup2(fd->fdfile[1], 1);
		dup2(fd->fd[2 * (cmd->p - 1)], 0);
		close(fd->fd[2 * (cmd->p - 1)]);
		close(fd->fd[2 * (cmd->p - 1) + 1]);
		close(fd->fdfile[1]);
		execve(cmd->pathstodos[cmd->i], cmd->flagtodos[cmd->i], env);
		exit(3);
	}
	close(fd->fdfile[1]);
	close(fd->fd[2 * (cmd->p - 1)]);
}
