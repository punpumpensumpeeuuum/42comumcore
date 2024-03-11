/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:17:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/11 17:41:31 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	init(int argc, t_stack *stack)
{
	stack->head = NULL;
	stack->sitio = argc - 1;
}

int	nocasodeserstring(int argc, char **argv, t_stack *a)
{
	int	*n;
	int	i;

	i = 0;
	if (!checknumb(argc, argv))
		return (0);
	argv = ft_split(argv[1], ' ');
	while (argv[i])
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

	init(argc, &a);
	init(argc, &b);
	if (argc <= 2 && !nocasodeserstring(argc, argv, &a))
	{
		ft_printf("Error\n");
		ft_lstclear(&(&a)->head, free);
		return (0);
	}
	if (argc > 2 && !getnumbers(argc, argv, &a))
	{
		ft_printf("Error\n");
		ft_lstclear(&(&a)->head, free);
		return (0);
	}
	if (!checknext((&a)->head))
	{
		if (argc <= 4)
			sort3(&(&a)->head);
	}
	ft_printf("Stack:\n");
	printa((&a)->head);
	ft_lstclear(&(&a)->head, free);
}
