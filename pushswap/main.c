/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemesmo <elemesmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:17:24 by dinda-si          #+#    #+#             */
/*   Updated: 2024/03/04 20:13:35 by elemesmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	stackprep(t_list *stack, int argc)
{
	stack->head = NULL;
	stack->sitio = argc - 1;
}

int	getnumbers(int argc, char **argv, t_list *a)
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
			return (0);
		i++;

	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	a;
	t_list	b;

	if (argc <= 2)
		return (0);
	stackprep(&a, argc);
	stackprep(&b, argc);
	if (!getnumbers(argc, argv, &a))
	{
		ft_printf("Error\n");
		ft_lstclear(&(&a)->head, free);
		return (0);
	}
	if (checknext((&a)->head))
	{
		ft_printf("a\n");
		if (argc <= 4)
			sort3(&(&a)->head);
	}
	ft_lstclear(&(&a)->head, free);
}
