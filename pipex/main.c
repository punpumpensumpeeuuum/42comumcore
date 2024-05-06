/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/06 18:37:20 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*checkcomand(char *cmd, char **env)
{
	int		i;
	int		p;
	char	*path = NULL;
	char	**paths = NULL;

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
				// ft_printf("1 >%s\n", cmd);
				path = ft_strjoin(paths[p], cmd, 1);
				ft_printf("%s\n", path);
				// ft_printf("%d\n", p);
				if (access(path, X_OK) == 0)
					return (path);
				else
				{
					ft_printf("fds\n");
					return (NULL);
				}
			}
		}
		i++;
	}
	path = NULL;
	return (path);
}

void	getcomand(t_cmds *cmd, char **av, char **env)
{
	int	j;

	j = 2;	
	cmd->flagtodos[cmd->i] = NULL;
	cmd->pathstodos[cmd->i] = NULL;
	cmd->flagtodos[cmd->i] = ft_split(av[j], ' ');
	if (cmd->flagtodos[cmd->i] == NULL)
	{
		ft_printf("errou as flgags\n");
		return ;
	}
	cmd->pathstodos[cmd->i] = checkcomand(cmd->pathstodos[cmd->i], env);
	if (cmd->pathstodos[cmd->i] == NULL)
	{
		ft_printf("errou os pahts\n");
		return ;
	}
	j++;
}

void	firstcmd(t_cmds *cmd, t_fds *fd, char **env, char **av)
{
	fd->fdfile[0] = open(av[1], O_RDONLY);
	if (fd->fdfile[0] == -1)
		return ;
	if (cmd->pathstodos[cmd->i] == NULL)
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
		dup2(fd->fd[1], 1);
		close(fd->fd[1]);
		close(fd->fd[0]);
		close(fd->fdfile[0]);
		if (cmd->pathstodos[cmd->i] != NULL)
			execve(cmd->pathstodos[cmd->i], cmd->flagtodos[cmd->i], env);
		exit(2);
	}
	close(fd->fdfile[0]);
	close(fd->fd[1]);
}

void	lastcmd(t_cmds *cmd, t_fds *fd, char **env, char **av)
{
	fd->fdfile[1] = open(av[4], O_WRONLY);
	if (fd->fdfile[1] == -1)
		return ;
	if (cmd->pathstodos[cmd->ac] == NULL)
	{
		ft_printf("num ha path\n");
		return ;
	}
	cmd->id2 = fork();
	if (cmd->id2 != 0)
		return ;
	else
	{
		dup2(fd->fdfile[1], 1);
		dup2(fd->fd[0], 0);
		close(fd->fd[0]);
		close(fd->fd[1]);
		close(fd->fdfile[1]);
		if (cmd->pathstodos[cmd->ac] != NULL)
			execve(cmd->pathstodos[cmd->ac], cmd->flagtodos[cmd->ac], env);
		exit(2);
	}
	close(fd->fdfile[1]);
	close(fd->fd[0]);
}

int	main(int ac, char **av, char **env)
{
	t_fds	fd;
	t_cmds	cmd;

	if (ac >= 5)
	{
		cmd.i = 0;
		cmd.ac = ac - 2;
		cmd.pathstodos = malloc(sizeof(char *) * (ac - 3));
		cmd.flagtodos = malloc(sizeof(char **) * (ac - 3));
		if (cmd.pathstodos == NULL || cmd.flagtodos == NULL) 
		{
			ft_printf("Memory allocation failed\n");
			exit(0);
        }
		while (cmd.i < cmd.ac)
		{
			getcomand(&cmd, av, env);
			cmd.i++;
		}
		cmd.i = 0;
		if (pipe(fd.fd) != -1)
		{
			firstcmd(&cmd, &fd, env, av);
			lastcmd(&cmd, &fd, env, av);
			close(fd.fd[0]);
			close(fd.fdfile[1]);
			waitpid(cmd.id1, NULL, 0);
		}
		free(cmd.pathstodos);
		free(cmd.flagtodos);
	}
}


    // Error Handling in checkcomand: You've added an error condition in the checkcomand function to return NULL if access to a path fails. This is a good addition for error handling.

    // Incrementing j in getcomand: You correctly increment j in the getcomand function after setting cmd->flagtodos[cmd->i]. This ensures you move to the next argument in av.

    // Error Messages: You've added error messages in case of memory allocation failure in main. This provides better feedback to users.

    // Memory Allocation in main: You've fixed the memory allocation size in main to use (ac - 3) instead of (ac - 2).

    // Formatting and Comments: It seems you've cleaned up some formatting and added comments, which improves readability.