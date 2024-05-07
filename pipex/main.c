/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/07 17:18:03 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initthings(t_cmds *cmd, int ac)
{
	cmd->i = 0;
	cmd->ac = ac - 4;
	cmd->avindex = 2;
	cmd->pathstodos = malloc(sizeof(char *) * (ac - 3));
	cmd->flagtodos = malloc(sizeof(char **) * (ac - 3));
	cmd->cmdtodos = malloc(sizeof(char *) * (ac - 3));
	if (cmd->pathstodos == NULL || cmd->flagtodos == NULL)
	{
		ft_printf("Memory allocation failed\n");
		exit(0);
	}
}

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

void	getcomand(t_cmds *cmd, char **av, char **env)
{
	cmd->flagtodos[cmd->i] = NULL;
	cmd->pathstodos[cmd->i] = NULL;
	cmd->flagtodos[cmd->i] = ft_split(av[cmd->avindex], ' ');
	cmd->cmdtodos[cmd->i] = cmd->flagtodos[cmd->i][0];
	if (cmd->flagtodos[cmd->i] == NULL)
	{
		ft_printf("errou as flgags\n");
		return ;
	}
	cmd->pathstodos[cmd->i] = checkcomand(cmd->cmdtodos[cmd->i], env);
	if (cmd->pathstodos[cmd->i] == NULL)
	{
		ft_printf("errou os pahts\n");
		return ;
	}
}

int	main(int ac, char **av, char **env)
{
	t_fds	fd;
	t_cmds	cmd;

	if (ac >= 5)
	{
		initthings(&cmd, ac);
		while (cmd.i < ac - 3)
		{
			getcomand(&cmd, av, env);
			cmd.i++;
			cmd.avindex++;
		}
		cmd.i = 0;
		if (pipe(fd.fd) != -1)
		{
			while (cmd.i < ac - 3)
			{
				piping(&cmd, &fd, env, av);
				cmd.avindex++;
				close(fd.fd[0]);
				close(fd.fdfile[1]);
				waitpid(cmd.id1, NULL, 0);
			}
		}
		free(cmd.pathstodos);
		free(cmd.flagtodos);
	}
}

/* errors a trata

sleep 5 | sleep 2 		pipe tem q correr ao memo tempo
varios cats da merda
valgrinds

*/