/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:18:52 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/29 16:26:59 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	sleepy(t_cmds *cmd)
{
	cmd->i = 0;
	while (cmd->i < cmd->ac + 1)
	{
		if (cmd->id1 == 0)
			cmd->i++;
		else if (cmd->id2 == 0)
			cmd->i++;
		else if (cmd->id3 == 0)
			cmd->i++;
		else
			cmd->i++;
		waitpid(-1, NULL, 0);
	}
}

void	closeall(t_fds *fd, t_cmds *cmd)
{
	int	i;

	i = 0;
	while (i < (cmd->ac + 1) * 2)
	{
		close(fd->fd[i]);
		i++;
	}
}

void	freefree(t_cmds *cmd, t_fds *fd)
{
	cmd->i = 0;
	cmd->p = 0;
	while (cmd->pathstodos[cmd->i])
		free(cmd->pathstodos[cmd->i++]);
	free(cmd->pathstodos);
	cmd->i = 0;
	while (cmd->flagtodos[cmd->i] && cmd->flagtodos)
	{
		while (cmd->flagtodos[cmd->i][cmd->p])
			free(cmd->flagtodos[cmd->i][cmd->p++]);
		cmd->p = 0;
		free(cmd->flagtodos[cmd->i++]);
	}
	free(cmd->flagtodos);
	free(cmd->cmdtodos);
	free(fd->fd);
	exit(5);
}

void	freepaths(char **paths, int i)
{
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	paths = NULL;
}
