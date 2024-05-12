/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:11:26 by elemesmo          #+#    #+#             */
/*   Updated: 2024/05/12 05:13:08 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	piping(t_cmds *cmd, t_fds *fd, char **env, char **av)
{
	// ft_printf("%d\n", cmd->p);
	// ft_printf("%d\n", cmd->ac);
	// ft_printf("%d\n", cmd->i);
	if (cmd->p == 0)
	{
		ft_printf("first\n");
		// ft_printf("pipe %d\n", fd->fd[cmd->p]);
		firstcmd(cmd, fd, env, av);
	}
	if (cmd->p != 0 && cmd->i < cmd->ac)
	{
		ft_printf("mid\n");
		// ft_printf("pipe %d\n", fd->fd[cmd->p]);
		mid1cmd(cmd, fd, env);
	}
	if (cmd->i == cmd->ac)
	{
		ft_printf("last\n");
		// ft_printf("pipe %d\n", fd->fd[cmd->p]);
		lastcmd(cmd, fd, env, av);
		close(fd->fd[cmd->p - 1]);
	}
	cmd->i++;
}

void	firstcmd(t_cmds *cmd, t_fds *fd, char **env, char **av)
{
	fd->fdfile[0] = open(av[1], O_RDONLY);
	if (fd->fdfile[0] == -1)
		return ;
	if (cmd->pathstodos[cmd->i] == NULL)
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
		if (cmd->pathstodos[cmd->i] != NULL)
			execve(cmd->pathstodos[cmd->i], cmd->flagtodos[cmd->i], env);
		exit(2);
	}
	close(fd->fdfile[0]);
	close(fd->fd[cmd->p + 1]);
}

void	mid1cmd(t_cmds *cmd, t_fds *fd, char **env)
{
	if (cmd->pathstodos[cmd->i] == NULL)
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
		if (cmd->pathstodos[cmd->i] != NULL)
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
	if (cmd->pathstodos[cmd->i] == NULL)
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
		if (cmd->pathstodos[cmd->i] != NULL)
			execve(cmd->pathstodos[cmd->i], cmd->flagtodos[cmd->i], env);
		exit(2);
	}
	close(fd->fdfile[1]);
	close(fd->fd[2 * (cmd->p - 1)]);
}
