/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 01:18:52 by elemesmo          #+#    #+#             */
/*   Updated: 2024/05/21 20:48:14 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freefree(t_cmds *cmd, t_fds *fd)
{
	cmd->i = 0;
	cmd->p = 0;
	while (cmd->pathstodos[cmd->i])
		free(cmd->pathstodos[cmd->i++]);
	free(cmd->pathstodos);
	cmd->i = 0;
	while (cmd->flagtodos[cmd->i])
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
