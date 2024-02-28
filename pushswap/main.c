/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:17:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/02/28 17:06:05 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*createnode(char *split)
{
	t_list	*stack;
	
	stack = malloc(sizeof(t_list));
	if (!stack)
		return (NULL);
	stack->content = ft_atoi(split);
	stack->sitio = 0;
	stack->next = NULL;
	return (stack);
}

t_list	*apendicar(t_list *stack, char **split)
{
	t_list	*head;
	int	i;

	i = 0;
	head = createnode(split[i]);
	stack = head;
	while (split[i])
	{
		stack->next = createnode(split[i]);
		stack = stack->next;
		i++;
	}
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**split;

	split = ft_split(argv[1], ' ');
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	a = apendicar(a, split);
	minisort(a);
}
