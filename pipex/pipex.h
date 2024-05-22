/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:42 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/22 14:34:48 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_fd
{
	int		*fd;
	int		fdfile[2];
}	t_fds;

typedef struct s_vars
{
	char	**pathstodos;
	char	***flagtodos;
	char	**cmdtodos;
	int		id1;
	int		id2;
	int		id3;
	int		ac;
	int		i;
	int		p;
	int		avindex;
	char	*minipath;
	char	**minipaths;
}	t_cmds;

void	checkhelp(char *comand, char **env, int i, t_cmds *cmd);
int		piping(t_cmds *cmd, t_fds *fd, char **env, char **av);
void	firstcmd(t_cmds *cmd, t_fds *fd, char **env, char **av);
void	midcmd(t_cmds *cmd, t_fds *fd, char **env);
void	lastcmd(t_cmds *cmd, t_fds *fd, char **env, char **av);

void	freefree(t_cmds *cmd, t_fds *fd);
void	freepaths(char **paths, int i);

#endif