/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:16:02 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/05 17:32:57 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int *content)
{
	struct s_list	*node;

	node = malloc(sizeof(struct s_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}