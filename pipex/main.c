/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/22 14:34:52 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initthings(t_cmds *cmd, int ac, t_fds *fd)
{
	cmd->id1 = 0;
	cmd->id2 = 0;
	cmd->id3 = 0;
	cmd->i = 0;
	cmd->ac = ac - 4;
	cmd->avindex = 2;
	cmd->p = 0;
	cmd->pathstodos = malloc(sizeof(char *) * (ac - 2));
	cmd->pathstodos[ac - 3] = NULL;
	cmd->flagtodos = malloc(sizeof(char **) * (ac - 2));
	cmd->flagtodos[ac - 3] = NULL;
	cmd->cmdtodos = malloc(sizeof(char *) * (ac - 2));
	cmd->cmdtodos[ac - 3] = NULL;
	fd->fd = malloc(sizeof(int) * ((ac - 3) * 2) + 1);
	while (cmd->i < (ac - 3))
	{
		if (pipe(fd->fd + 2 * cmd->i) < 0)
			return ;
		cmd->i++;
	}
	cmd->i = 0;
	if (cmd->pathstodos == NULL || cmd->flagtodos == NULL)
		return ;
}

char	*checkcomand(char *comand, char **env, t_cmds *cmd)
{
	int		i;

	i = 0;
	cmd->avindex = 2;
	if (access(comand, X_OK) == 0)
	{
		cmd->minipath = comand;
		return (cmd->minipath);
	}
	cmd->avindex = 2;
	checkhelp(comand, env, i, cmd);
	return (cmd->minipath);
}

void	getcomand(t_cmds *cmd, char **av, char **env)
{
	cmd->flagtodos[cmd->i] = NULL;
	cmd->pathstodos[cmd->i] = NULL;
	cmd->flagtodos[cmd->i] = ft_split(av[cmd->i + 2], ' ');
	cmd->cmdtodos[cmd->i] = cmd->flagtodos[cmd->i][0];
	cmd->pathstodos[cmd->i] = checkcomand(cmd->cmdtodos[cmd->i], env, cmd);
	if (cmd->pathstodos[cmd->i] == NULL || cmd->flagtodos[cmd->i] == NULL)
	{
		cmd->pathstodos[cmd->i] = ft_strdup("error");
		ft_printf("errou os paths ou as flags\n");
		return ;
	}
}

int	main(int ac, char **av, char **env)
{
	t_fds	fd;
	t_cmds	cmd;

	if (ac >= 5)
	{
		initthings(&cmd, ac, &fd);
		while (cmd.i < ac - 3)
		{
			getcomand(&cmd, av, env);
			cmd.i++;
			cmd.avindex++;
		}
		cmd.i = 0;
		while (cmd.i < ac - 3)
		{
			if (piping(&cmd, &fd, env, av) != 0)
				freefree(&cmd, &fd);
			cmd.avindex++;
			cmd.p++;
		}
		waitpid(cmd.id1, NULL, 0);
		freefree(&cmd, &fd);
	}
}

// ft_printf("0: %d\n", fd.fd[2 * cmd.p]);
// ft_printf("1: %d\n", fd.fd[2 * cmd.p + 1]);