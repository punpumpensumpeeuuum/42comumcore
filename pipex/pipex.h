/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:21:42 by dinda-si          #+#    #+#             */
/*   Updated: 2024/05/06 17:00:24 by dinda-si         ###   ########.fr       */
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
	int	fd[2];
	int	fdfile[2];
}	t_fds;

typedef struct s_vars
{
	char	**pathstodos;
	char	***flagtodos;
	char	**cmdtodos;
	int		id1;
	int		id2;
	int		ac;
	int		i;
}	t_cmds;

#endif