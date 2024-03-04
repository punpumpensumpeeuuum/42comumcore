/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:45:21 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/04 19:39:58 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int					ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_itoa(int n);
int					ft_putchar_fd(char c, int fd);
int					ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s);

typedef struct s_atoa
{
	struct s_atoa	*head;
	int				sitio;
	int				*content;
	struct s_atoa	*next;
}	t_list;

int					ft_lstsize(t_list *lst);
t_list				*ft_lstnew(void *c);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
