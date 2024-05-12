/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:42 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/12 03:50:57 by elemesmo         ###   ########.fr       */
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
}	t_cmds;

void	concertaropipe(t_fds *fd, t_cmds *cmd);
void	piping(t_cmds *cmd, t_fds *fd, char **env, char **av);
void	firstcmd(t_cmds *cmd, t_fds *fd, char **env, char **av);
void	mid1cmd(t_cmds *cmd, t_fds *fd, char **env);
void	mid2cmd(t_cmds *cmd, t_fds *fd, char **env, char **av);
void	lastcmd(t_cmds *cmd, t_fds *fd, char **env, char **av);

#endif