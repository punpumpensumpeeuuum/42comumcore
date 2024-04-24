/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:45:21 by dinda-si          #+#    #+#             */
/*   Updated: 2024/04/10 15:13:24 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
