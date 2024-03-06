/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinda-si <dinda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:17:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/06 16:57:05 by dinda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init(int argc, t_stack *stack)
{
	stack->head = NULL;
	stack->sitio = argc - 1;
}

int	getnumbers(int argc, char **argv, t_stack *a)
{
	int	i;
	int	*n;

	i = 1;
	if (!checknumb(argc, argv))
		return (0);
	while (i < argc)
	{
		n = malloc(sizeof(int));
		*n = ft_atoi(argv[i]);
		if (!checkdup(a->head, n))
			ft_lstadd_back(&a->head, ft_lstnew(n));
		else
		{
			free(n);
			return (0);
		}
		i++;
	}			
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc <= 2)
		return (0);
	init(argc, &a);
	init(argc, &b);
	if (!getnumbers(argc, argv, &a))
	{
		ft_printf("Error\n");
		ft_lstclear(&(&a)->head, free);
		return (0);
	}
	if (!checknext((&a)->head))
	{
		if (argc <= 4)
		{
			sort3(&(&a)->head);
		}
	}
	// printa(&a);
	// ft_lstclear(&(&a)->head, free);
}
