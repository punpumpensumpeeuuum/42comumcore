/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:18:52 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/28 14:42:53 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	closeall(t_fds *fd, t_cmds *cmd)
{
	int	i;

	i = 0;
	// ft_printf("2: %d\n", (cmd->ac + 1) * 2);
	while (i < (cmd->ac + 1) * 2)
	{
		ft_printf("fd: %d\n", fd->fd[i]);
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
